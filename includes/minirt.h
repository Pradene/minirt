#ifndef MINIRT
# define MINIRT

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

# define WIDTH 1920
# define HEIGHT 1080
# define PI 3.14159265359
# define ASPECT_RATIO (float)WIDTH / (float)HEIGHT

typedef float m4 __attribute__((matrix_type(4, 4)));
typedef float v4 __attribute__((ext_vector_type(4)));
typedef float v3 __attribute__((ext_vector_type(3)));
typedef float v2 __attribute__((ext_vector_type(2)));

typedef struct s_object
{
	v3      position;
	v3      rotate;
	v3      scale;
	float	radius;
}	t_object;

typedef struct s_camera
{
    m4      view;
    m4      projection;
	v3      position;
	v3      rotate;
	v3      direction;
	float	near;
	float	far;
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
	t_object	object;
	v2          mouse_pos;
}   t_data;

int     quit(t_data	*data);

// CAMERA
void    move_camera_position(t_camera *cam, float x, float y, float z);
void    new_camera(t_camera *cam, v3 position, int fov);

// EVENT
int     mouse(int x, int y, t_data *data);
int     key(int keycode, t_data *data);

// MATH
void    matprint(m4 m);
void    imatrix(m4 *m);

void    v3print(v3 v);
v3      vec3(float x, float y, float z);
void    v4print(v4 v);
v4      vec4(float x, float y, float z, float w);
v4      mult_v4_m4(m4 m, v4 v);

float   dot(v3 p, v3 q);
v3      normalize(v3 vec);
v3      vec3_substract(v3 a, v3 b);

// OBJECT
t_object    sphere(v3 pos, float radius);

// RENDER
int     intersect(t_data *data, v2 coord);
void    trace(t_data *data, t_image *img);
int     update(t_data *data);
void    render(t_data *data);

// RENDERER
void    renderer(t_data *data, char *name);

// UTILS
void	pixel_put(t_image *img, int x, int y, int color);
float   clamp(float v, float min, float max);
int     rgba_to_color(float r, float g, float b, float a);
float   min_float(float n1, float n2);
float   radian(float angle);

#endif