#include "../includes/minirt.h"

float   dot(t_vec3 p, t_vec3 q)
{
    return (p.x * q.x + p.y * q.y + p.z * q.z);
}

t_vec3  vec3(float x, float y, float z)
{
    t_vec3  v;

    v.x = x;
    v.y = y;
    v.z = z;
    return (v);
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

t_vec3  vec3_substract(t_vec3 a, t_vec3 b)
{
    t_vec3  v;

    v.x = a.x - b.x;
    v.y = a.y - b.y;
    v.z = a.z - b.z;
    return (v);
}
