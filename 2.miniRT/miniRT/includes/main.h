#ifndef MAIN_H
# define MAIN_H

#include "get_next_line.h"
#include "../libft/libft.h"
#include <stdio.h> //printf
#include <math.h> //pow
#include <fcntl.h> //open
#include <stdlib.h> //malloc, free
#include "mlx.h"

# define SP 0
# define PL 1
# define SQ 2
# define TR 3
# define CY 4
# define LUMEN 3
# define FALSE 0
# define TRUE 1
# define EPSILION 1e-6

typedef int		t_bool;

typedef struct	s_p3
{
	double x;
	double y;
	double z;
}				t_p3;

//카메라 구조체
typedef struct 	s_cam
{
	t_p3 position;
	t_p3 dir_vec;
	int fov;
	double viewport_h;
	double viewport_w;
	double focal_length;
	t_p3 origin;
	t_p3 horizontal;
	t_p3 vertical;
	t_p3 l_l_corner;

	struct s_cam *next;
	//etc
}				t_cam;

//카메라가 보이는 곳
typedef struct s_hit_record
{
	t_p3 p_meet;
	t_p3 normal;
	double tmin;
	double tmax;
	double oc_r;
	t_bool front_face;
	t_p3 albedo;
}				t_hit_record;

//광선 구조체
typedef struct  s_ray
{
    t_p3     orig;
    t_p3       dir;
	float t;
}               t_ray;

//빛 구조체
typedef struct 	s_light
{
	t_p3 position;
	double br;
	t_p3 color;
	struct s_light *next;
}				t_light;

//장면 구조체
typedef struct	s_scene
{
	int res_x;
	int res_y;
	int res_ex;

	double amb_ratio;
	t_p3 amb_color;
	int amb_ex;

	t_light *l;
}				t_scene;

//fig
typedef struct	s_sp
{
	t_p3 c;
	double r;
	int inside;
}				t_sp;

typedef struct 	s_pl
{
	t_p3 position;
	t_p3 normal;
}				t_pl;

typedef struct	s_sq
{
	t_p3 sq_c;
	t_p3 normal;
	double length;
}				t_sq;

typedef struct	s_cy
{
	t_p3 c;
	t_p3 normal;
	double r;
	double h;
}				t_cy;

typedef struct	s_tr
{
	t_p3 first;
	t_p3 second;
	t_p3 third;
}				t_tr;

union	u_fig
{
	t_sp	sp;
	t_pl	pl;
	t_sq	sq;
	t_cy	cy;
	t_tr	tr;

};

//fig
typedef struct s_fig
{
	int				flag;
	union	u_fig 	fig;
	t_p3 			albedo;

	struct	s_fig 	*next;
	//..+a
}				t_fig;

//mlx
typedef struct	s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	
	int	*data;
	int bpp;
	int size_l;
	int endian;

	t_cam	*cam; 
}				t_mlx;

typedef struct	s_matrix
{
	int x;
	int y;
	double u;
	double v;
}				t_matrix;

typedef struct	s_discriminant
{
	double a;
	double half_b;
	double c;
	double discriminant;
	double sqrtd;
	double root;
}				t_discriminant;

#include "parse_utils.h"
#include "parse.h"
#include "split_etc.h"
#include "split_figure.h"
#include "vec_operation.h"
#include "ray.h"
#include "vec_mul.h"
#include "vec_utils.h"
#include "draw_view.h"
#include "hit_fig.h"


void parse(t_mlx *mlx, t_scene *data, t_fig **lst, char **av);
void find_figure(t_mlx *mlx, t_scene *data, t_fig **lst, char *str);
int key_press(int key, t_mlx mlx);

#endif
