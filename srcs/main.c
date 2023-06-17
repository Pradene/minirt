#include "../includes/minirt.h"

int quit(t_data	*data)
{
    if (data->id && data->img.image)
	    mlx_destroy_image(data->id, data->img.image);
	if (data->id && data->win)
        mlx_destroy_window(data->id, data->win);
	if (data->id)
        mlx_destroy_display(data->id);
	free(data->id);
	exit(EXIT_SUCCESS);
}

int main(void)
{
    t_data  data;

	data.mouse_pos.x = 0;
	data.mouse_pos.y = 0;
    renderer(&data, "miniRT");
    new_camera(&data.camera, vec3(0.0, 0.0, 0.0), 70);
	data.object = sphere(vec3(0.0, 0.0, -5.0), 1.5);
	render(&data);

	m4 m;
	imatrix(&m);
	m4 res = m * 2;
	matprint(res);
    return (0);
}