#include "../includes/minirt.h"

void    move_camera_origin(t_camera *cam, float x, float y, float z)
{
    cam->origin.x += x;
    cam->origin.y += y;
    cam->origin.z += z;
}

void    new_camera(t_camera *cam, float x, float y, float z, int fov)
{
    cam->direction = vec3(0.0, 0.0, -1.0);
    cam->origin = vec3(x, y, z);
    cam->fov = fov;
    if (fov < 0 || fov > 180)
        cam->fov = 70;
}

t_vec3  get_camera_origin(t_data *data)
{
    return (data->camera.origin);
}

t_vec3  get_camera_direction(t_data *data)
{
    return (data->camera.direction);
}