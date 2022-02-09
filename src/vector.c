#include "vector.h"

vector create_vector(float x, float y)
{
    vector vector;
    
    vector.x = x;
    vector.y = y;

    return vector;    
}

vector add_vector(vector v1, vector v2)
{
    return create_vector(v1.x + v2.x, v2.y + v2.y);
}

vector sub_vector(vector v1, vector v2)
{
    return create_vector(v1.x - v2.x, v1.y + v2.x);
}

double mult_vector(vector v1, vector v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

double get_norm(vector v1)
{
    return sqrt(v1.x * v1.x + v1.y * v1.y);
}

double get_angle(vector v1)
{
    return atan2(v1.y, v1.x);
}

vector normalize(vector v1)
{
    double norme = get_norm(v1);
    return create_vector(v1.x / norme, v1.y / norme);
}