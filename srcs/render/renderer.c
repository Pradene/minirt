#include "../../includes/minirt.h"

void    renderer(t_data *data, char *name)
{
    data->win = NULL;
    data->img.image = NULL;
    data->img.data = NULL;
    data->id = mlx_init();
    if (!data->id)
        quit(data);
    data->win = mlx_new_window(data->id, WIDTH, HEIGHT, name);
    data->img.image = mlx_new_image(data->id, WIDTH, HEIGHT);
    data->img.data = mlx_get_data_addr(data->img.image, &data->img.bpp,
        &data->img.size_line, &data->img.endian);
}