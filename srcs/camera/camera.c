#include "../../includes/minirt.h"

void    new_camera(t_camera *cam, v3 position, int fov)
{
    cam->direction = vec3(0.0, 0.0, -1.0);
    cam->position = position;
    cam->rotate = vec3(0.0, 0.0, 0.0);
    cam->fov = fov;
    if (fov < 0 || fov > 180)
        cam->fov = 45;
}
