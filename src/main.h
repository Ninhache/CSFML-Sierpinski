#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/System.h>

sfVertexArray* get_triangle(sfVector2f p1, sfVector2f p2, sfVector2f p3);
sfVertex create_vertex(sfVector2f position, sfColor color, sfVector2f texCoords);
sfVector2f create_vectorF(float x, float y);
sfVector2u create_vectorU(float x, float y);
sfRenderWindow* create_window(unsigned int width, unsigned int height, char const *title);
void sierpinskiLoop(sfRenderWindow* window);
void sierpinskiW(sfRenderWindow* window, sfVector2f p1, sfVector2f p2, sfVector2f p3, int limit);
void draw_triangleW(sfRenderWindow* window, sfVector2f p1, sfVector2f p2, sfVector2f p3);
int main();