#include "../../includes/minirt.h"

float   dot(v3 p, v3 q)
{
    return (p.x * q.x + p.y * q.y + p.z * q.z);
}

v3  normalize(v3 vec)
{
    v3  v;
    float   magnitude;

    magnitude = sqrt(dot(vec, vec));
    v.x = vec.x / magnitude;
    v.y = vec.y / magnitude;
    v.z = vec.z / magnitude;
    return (v);
}

void    v3print(v3 v)
{
    int i;

    i = -1;
    while (++i < 3)
        printf("%lf ", v[i]);
    printf("\n");
}

void    v4print(v4 v)
{
    int i;

    i = -1;
    while (++i < 4)
        printf("%lf ", v[i]);
    printf("\n");
}

v3  vec3(float x, float y, float z)
{
    v3  v;

    v.x = x;
    v.y = y;
    v.z = z;
    return (v);
}

v4  vec4(float x, float y, float z, float w)
{
    v4  v;

    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return (v);
}

v4  mult_v4_m4(m4 m, v4 v)
{
    v4  vec;
    int i;
    int j;

    i = -1;
    while (++i < 4)
    {
        j = -1;
        vec[i] = 0;
        while (++j < 4)
            vec[i] += v[j] * m[i][j];
    }
    return (vec);
}
