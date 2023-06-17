#include "../../includes/minirt.h"

int intersect(t_data *data, v2 coord)
{
    float   a;
    float   b;
    float   c;
    v3      ray_direction;
    v3      ray_origin;

    ray_origin = data->camera.position - data->object.position;
    ray_direction = data->camera.direction + vec3(coord.x, coord.y, 0);
    ray_direction = normalize(ray_direction);
    a = dot(ray_direction, ray_direction);
    b = 2.0 * dot(ray_origin, ray_direction);
    c = dot(ray_origin, ray_origin) - data->object.radius * data->object.radius;
    if (b * b - 4.0 * a * c < 0.0)
        return (rgba_to_color(0.0, 0.0, 0.0, 1.0));
    float t = (-b - sqrt(b * b - 4.0 * a * c)) / (2.0 * a);
    if (t < 0)
        return (rgba_to_color(0.0, 0.0, 0.0, 1.0));
    v3 hp = ray_origin + ray_direction * t;
    hp = normalize(hp);
    return (rgba_to_color(hp.x, hp.y, hp.z, 1.0));
}

void    trace(t_data *data, t_image *img)
{
    float   y;
    float   x;
    int     fov;
    v2      coord;
    int32_t color;

    y = -1;
    fov = data->camera.fov;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            coord.x = (((x + 0.5) / WIDTH) * 2.0 - 1.0) * ASPECT_RATIO * tan(radian(fov / 2));
            coord.y = (((HEIGHT - (y + 0.5)) / HEIGHT) * 2.0 - 1.0) * tan(radian(fov / 2));
            color = intersect(data, coord);
            pixel_put(img, x, y, color);
        }
    }
}

int update(t_data *data)
{
    if (!data->win)
        return (1);
    trace(data, &data->img);
    mlx_put_image_to_window(data->id, data->win, data->img.image, 0, 0);
    return (0);
}

void    render(t_data *data)
{
    mlx_loop_hook(data->id, &update, data);
	mlx_hook(data->win, 2, 1L << 0, &key, data);
    mlx_hook(data->win, 6, 1L << 6, &mouse, data);
	mlx_hook(data->win, 17, 0, &quit, data);
    mlx_loop(data->id);
}
