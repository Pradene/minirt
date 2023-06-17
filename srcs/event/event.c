#include "../includes/minirt.h"

int	mouse(int x, int y, t_data *data)
{
	float	speed;

	speed = 0.6;
	data->camera.rotate.x += (float)((x - data->mouse_pos.x) * speed);
	data->camera.rotate.y += (float)((y - data->mouse_pos.y) * speed);
	data->mouse_pos.x = x;
	data->mouse_pos.y = y;
	// printf("%lf, %lf\n", data->camera.rotate.x, data->camera.rotate.y);
	return (0);
}

int	key(int keycode, t_data *data)
{
	// printf("%d\n", keycode);
	if (keycode == 119)
		data->camera.position += vec3(0, 0, -0.01);
	if (keycode == 115)
		data->camera.position += vec3(0, 0, 0.01);
	if (keycode == 97)
		data->camera.position += vec3(-0.01, 0, 0);
	if (keycode == 100)
		data->camera.position += vec3(0.01, 0, 0);
	if (keycode == 65307)
		quit(data);
	return (0);
}
