#include "../includes/minirt.h"

void    set_camera_origin(t_camera *cam, float x, float y, float z)
{
    cam->origin.x = x;
    cam->origin.y = y;
    cam->origin.z = z;
}

void    move_camera_origin(t_camera *cam, float x, float y, float z)
{
    cam->origin.x += x;
    cam->origin.y += y;
    cam->origin.z += z;
}

void    set_camera_direction(t_camera *cam, float x, float y, float z)
{
    cam->direction.x = x;
    cam->direction.y = y;
    cam->direction.z = z;
}

void    new_camera(t_camera *cam, float x, float y, float z, int fov)
{
    set_camera_origin(cam, x, y, z);
    set_camera_direction(cam, 0.0, 0.0, -1.0);
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