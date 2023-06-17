#include "../../includes/minirt.h"

void    matprint(m4 m)
{
    int i;
    int j;

    i = -1;
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
            printf("%lf ", m[i][j]);
        printf("\n");
    }
}

void    imatrix(m4 *m)
{
    int i;
    int j;

    i = -1;
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
        {
            (*m)[i][j] = 0;
            if (i == j)
                (*m)[i][j] = 1;
        }
    }
}
