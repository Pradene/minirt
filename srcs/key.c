#include "../includes/minirt.h"

int	key(int keycode, t_data *data)
{
	printf("%d\n", keycode);
	if (keycode == 119)
		move_camera_origin(&data->camera, 0, 0, -0.01);
	if (keycode == 115)
		move_camera_origin(&data->camera, 0, 0, 0.01);
	if (keycode == 97)
		move_camera_origin(&data->camera, -0.01, 0, 0);
	if (keycode == 100)
		move_camera_origin(&data->camera, 0.01, 0, 0);
	if (keycode == 65307)
		quit(data);
	return (0);
}
