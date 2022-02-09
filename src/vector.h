#include "math.h"

typedef struct
{
    float x;
    float y;
} vector;

vector create_vector(float x, float y);

vector add_vector(vector v1, vector v2);

vector sub_vector(vector v1, vector v2);

double mult_vector(vector v1, vector v2);

double get_norm(vector v1);

double get_angle(vector v1);

vector normalize(vector v1);
