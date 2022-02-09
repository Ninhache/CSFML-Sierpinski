#include "math.h"

typedef struct
{
    float r;
    float i;
} complex;

complex create_complex(float r, float i);

complex add_complex(complex c1, complex c2);

complex sub_complex(complex c1, complex c2);

complex mult_complex(complex c1, complex c2);

complex div_complex(complex c1, complex c2);

complex exp_complex(complex c1, int n);