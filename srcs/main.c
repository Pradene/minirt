#include "../includes/minirt.h"

int quit(t_data	*data)
{
	mlx_destroy_image(data->id, data->img.image);
	mlx_destroy_window(data->id, data->win);
	mlx_destroy_display(data->id);
	free(data->id);
	exit(EXIT_SUCCESS);
}

int main(void)
{
	t_data  data;

	renderer(&data, "miniRT");
    new_camera(&data.camera, 0, 0, 2.0, 70);
	render(&data);
	return (0);
}
