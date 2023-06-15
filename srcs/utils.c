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

float   dot(t_vec3 p, t_vec3 q)
{
    return (p.x * q.x + p.y * q.y + p.z * q.z);
}

t_vec3  get_hitpoint(t_vec3 a, t_vec3 b, float t)
{
    t_vec3  h;

    h.x = a.x + b.x * t;
    h.y = a.y + b.y * t;
    h.z = a.z + b.z * t;
    return (h);
}

t_vec3  normalize(t_vec3 vec)
{
    t_vec3  v;
    float   magnitude;

    magnitude = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    v.x = vec.x / magnitude;
    v.y = vec.y / magnitude;
    v.z = vec.z / magnitude;
    return (v);
}

float   min_float(float n1, float n2)
{
    if (n1 > n2)
        return (n2);
    return (n1);
}
