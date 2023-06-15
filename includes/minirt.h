#ifndef MINIRT
# define MINIRT

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

# include <math.h>
# include <stdio.h>

# define WIDTH 1920
# define HEIGHT 1080
# define ASPECT_RATIO (float)WIDTH / (float)HEIGHT

typedef struct s_vec2
{
	float   x;
	float   y;
}   t_vec2;

typedef struct s_vec3
{
	float   x;
	float   y;
	float   z;
}   t_vec3;

typedef struct s_vec4
{
	float   r;
	float   g;
	float   b;
	float   a;
}   t_vec4;

typedef struct s_camera
{
	t_vec3  origin;
	t_vec3  direction;
	int		fov;
}   t_camera;

typedef struct s_image
{
	void	*image;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_data
{
	void		*id;
	void		*win;
	t_image		img;
	t_camera	camera;
}   t_data;

// INITIALISATION
void    renderer(t_data *data, char *name);

// KEY
int		key(int keycode, t_data *data);

// CAMERA
void    new_camera(t_camera *cam, float x, float y, float z, int fov);
void    move_camera_origin(t_camera *cam, float x, float y, float z);
t_vec3  get_camera_origin(t_data *data);
t_vec3  get_camera_direction(t_data *data);

// RENDER
void	render(t_data *data);
void	pixel_put(t_image *img, int x, int y, int color);

// UTILS
float   dot(t_vec3 p, t_vec3 q);
t_vec3  get_hitpoint(t_vec3 a, t_vec3 b, float t);
int 	rgba_to_color(float r, float g, float b, float a);
t_vec3	normalize(t_vec3 vec);
float   min_float(float n1, float n2);

// EXIT
int		quit(t_data *data);

#endif