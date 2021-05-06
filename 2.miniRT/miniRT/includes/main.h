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


typedef struct	s_p3
{
	double x;
	double y;
	double z;
}				t_p3;

typedef struct 	s_light
{
	t_p3 position;
	double br;
	int color;
	struct s_light *next;
}				t_light;

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

typedef int t_bool;
#define FALSE 0
#define TRUE 1

typedef struct s_hit_record
{
	t_p3 p_meet;
	t_p3 normal;
	double tmin;
	double tmax;
	double d_rorig_meet;
	t_bool front_face;
}				t_hit_record;

typedef struct  s_ray
{
    t_p3     orig;
    t_p3       dir;
	float t;
}               t_ray;

typedef struct	s_scene
{
	int res_x;
	int res_y;
	int res_ex;

	double amb_ratio;
	int amb_color;
	int amb_ex;

	t_light *l;
	//...etc
}				t_scene;

//장면 구조체
typedef struct	s_sp //sphere
{
	t_p3 c;
	double r;
	int inside;
}				t_sp;

typedef struct 	s_pl
{
	t_p3 position;
	t_p3 normal;
	int color;
}				t_pl;

typedef struct	s_sq
{
	t_p3 sq_c;
	t_p3 normal;
	double length;
	int color;
}				t_sq;

typedef struct	s_cy
{
	t_p3 c;
	t_p3 normal;
	double r;
	double h;
	int color;
}				t_cy;

typedef struct	s_tr
{
	t_p3 first;
	t_p3 second;
	t_p3 third;
	int color;
}				t_tr;

union	u_fig
{
	t_sp	sp;
	t_pl	pl;
	t_sq	sq;
	t_cy	cy;
	t_tr	tr;

};
//union으로서 하나의 도형만 받도록~

typedef struct s_fig
{
	int				flag;
	union	u_fig 	fig;
	int 			color;
	struct	s_fig 	*next;
	//..+a
}				t_fig;
//도형 구조체

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

#include "parse_utils.h"
#include "parse.h"
#include "split_etc.h"
#include "split_figure.h"
#include "vec_operation.h"
#include "ray.h"

void parse(t_mlx *mlx, t_scene *data, t_fig **lst, char **av);

#endif
