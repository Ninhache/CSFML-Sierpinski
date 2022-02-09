#include "complex.h"

complex create_complex(float r, float i)
{
    complex complex;
    complex.r = r;
    complex.i = i;

    return complex;
}

complex add_complex(complex c1, complex c2)
{
    return create_complex(c1.r + c2.r, c1.i + c2.i);
}

complex sub_complex(complex c1, complex c2)
{
    return create_complex(c1.r - c2.r, c1.i - c2.i);
}

complex mult_complex(complex c1, complex c2)
{
    return create_complex(c1.r * c2.r - c1.i * c2.i ,  c1.r * c2.i + c1.i * c2.r);
}

complex div_complex(complex c1, complex c2)
{
    return create_complex((c1.r * c2.r + c1.i * c2.i) / (pow(c2.r, 2) + pow(c2.i, 2)), (c1.i * c2.r - c1.r * c2.i) / (pow(c2.r, 2) + pow(c2.i, 2)));
}

complex exp_complex(complex c1, int n)
{
    if(n == 2)
    {
        return create_complex(c1.r * c1.r - c1.i * c1.i, 2. * c1.r * c1.i);

        complex result = create_complex(1, 0);

        for(int i = 0 ; i < n ; i++)
        {
            result = mult_complex(result, c1);
        }

        return result;
    }
}