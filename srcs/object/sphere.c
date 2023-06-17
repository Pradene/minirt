#include "../../includes/minirt.h"

t_object    sphere(v3 pos, float radius)
{
    t_object    sp;

    sp.radius = radius;
    sp.position = pos;
    sp.scale = vec3(1.0, 1.0, 1.0);
    sp.rotate = vec3(0.0, 0.0, 0.0);
    return (sp);
}
