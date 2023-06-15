#include "../includes/minirt.h"

int32_t  intersect(t_data *data, t_vec2 coord)
{
    float   a;
    float   b;
    float   c;
    float   r;
    t_vec3  ray_direction;
    t_vec3  ray_origin;

    r = 0.5;
    ray_origin = get_camera_origin(data);
    ray_direction = get_camera_direction(data);
    ray_direction.x += coord.x;
    ray_direction.y += coord.y;
    ray_direction = normalize(ray_direction);
    a = dot(ray_direction, ray_direction);
    b = 2.0 * dot(ray_origin, ray_direction);
    c = dot(ray_origin, ray_origin) - r * r;
    if (b * b - 4.0 * a * c < 0.0)
        return (0x000000);
    float t0 = (-b - sqrt(b * b - 4.0 * a * c)) / (2.0 * a);
    float t1 = (-b + sqrt(b * b - 4.0 * a * c)) / (2.0 * a);
    float closest = min_float(t0, t1);
    t_vec3 hp = get_hitpoint(ray_origin, ray_direction, closest);
    return (rgba_to_color(hp.x, hp.y, hp.z, 1.0));
}

void    trace(t_data *data, t_image *img)
{
    float   y;
    float   x;
    t_vec2  coord;
    int32_t color;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            coord.x = ((x / WIDTH) * 2.0 - 1.0) * ASPECT_RATIO;
            coord.y = ((HEIGHT - y) / HEIGHT) * 2.0 - 1.0;
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
	mlx_hook(data->win, 17, 0, &quit, data);
    mlx_loop(data->id);
}
