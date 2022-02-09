#include <stdlib.h>
#include <stdio.h>
#include "main.h"



sfVertexArray* get_triangle(sfVector2f p1, sfVector2f p2, sfVector2f p3)
{
    sfVertexArray* triangle = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(triangle, sfTriangles);

    sfVertexArray_append(triangle, create_vertex(create_vectorF(100,200), sfColor_fromRGB(255,255,255),  create_vectorF(100,200)));
    sfVertexArray_append(triangle, create_vertex(create_vectorF(200,300), sfColor_fromRGB(  0,255,  0),  create_vectorF(200,300)));
    sfVertexArray_append(triangle, create_vertex(create_vectorF(300,100), sfColor_fromRGB(  0, 55,100),  create_vectorF(300,100)));

    return triangle;
}

sfVertex create_vertex(sfVector2f position, sfColor color, sfVector2f texCoords)
{
    sfVertex vertex;
    
    vertex.position = position;
    vertex.color = color;
    vertex.texCoords = texCoords;

    return vertex;
}

sfVector2f create_vectorF(float x, float y)
{
    sfVector2f vector;
    vector.x = x;
    vector.y = y;
    return vector;
}


sfRenderWindow* create_window(unsigned int width, unsigned int height, char const *title)
{
    sfRenderWindow *Window;
    sfVideoMode mode;

    mode.width = width;
    mode.height = height;
    mode.bitsPerPixel = 256;
    Window = sfRenderWindow_create(mode, title, sfDefaultStyle, NULL);

    return (Window);
}

void sierpinskiW(sfRenderWindow* window, sfVector2f p1, sfVector2f p2, sfVector2f p3, int limit)
{
    
    if(limit > 0)
    {
        sfVector2f pa = create_vectorF((p1.x + p2.x)/2, (p1.y + p2.y)/2),
                   pb = create_vectorF((p2.x + p3.x)/2, (p2.y + p3.y)/2),
                   pc = create_vectorF((p3.x + p1.x)/2, (p3.y + p1.y)/2);
        
        sierpinskiW(window, p1, pa, pc, limit - 1);
        sierpinskiW(window, pa, p2, pb, limit - 1);
        sierpinskiW(window, pc, pb, p3, limit - 1);
    } else {
        draw_triangleW(window, p1, p2, p3);
    }
}

void draw_triangleW(sfRenderWindow* window, sfVector2f p1, sfVector2f p2, sfVector2f p3) {

    sfVertexArray* triangle = get_triangle(p1, p2, p3);

    sfRenderWindow_drawVertexArray(window, triangle, NULL);

    free(triangle);

}

void sierpinskiLoop(sfRenderWindow* window)
{

    sfVector2u size = sfRenderWindow_getSize(window);

    sierpinskiW(window, create_vectorF(0,-321), create_vectorF(278, 160), create_vectorF(-278,160), 0);
}

sfVector2u create_vectorU(float x, float y)
{
    sfVector2u vector;

    vector.x = x;
    vector.y = y;

    return vector;
}

int main()
{

    sfRenderWindow* window = create_window(800, 800, "CSFML");
    sfEvent event;

    sfVector2u size = sfRenderWindow_getSize(window);    
    //sfRenderWindow_

    //sfVideoMode
    //sfRenderWindow_

    //sfView_move(sfRenderWindow_getView(window), create_vectorF(size.x/2, size.y/2));
    
    /*
    sfThread* thread = sfThread_create(sierpinskiLoop, window);
    sfThread_launch(thread);
    */

    while (sfRenderWindow_isOpen(window))
    {
        //sfRenderWindow_clear(window, sfBlack);

        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
                sfRenderWindow_close(window);
            }
        }

        //draw_triangleW(window, create_vectorF(size.x/2,100), create_vectorF(size.x/3, size.y/2 + size.y/3), create_vectorF(size.x/3 + size.x/3, size.y/3 + size.y/2));
        printf("SIZE X: %f | Y: %f\n", size.x, size.y);

        sfRenderWindow_display(window);
    }

    sfRenderWindow_destroy(window);
    return 0;
}
