#include "../includes/minirt.h"

float clamp(float v, float min, float max)
{
    if (v < min)
        return (min);
    else if (v > max)
        return (max);
    return (v);
}

int rgba_to_color(float r, float g, float b, float a)
{
    int color;

    r = clamp(r, 0.0, 1.0);
    g = clamp(g, 0.0, 1.0);
    b = clamp(b, 0.0, 1.0);
    a = clamp(a, 0.0, 1.0);
    color = ((int)(a * 255) << 24) | ((int)(r * 255) << 16) \
    | ((int)(g * 255) << 8) | ((int)(b * 255) << 0);
    return (color);
}

float   min_float(float n1, float n2)
{
    if (n1 > n2 && n2 > 0.0)
        return (n2);
    return (n1);
}
