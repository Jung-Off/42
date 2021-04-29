#ifndef MAIN_H
# define MAIN_H

#include "get_next_line.h"
#include "../libft/libft.h"
#include <stdio.h> //printf

#include <math.h> //pow
#include <fcntl.h> //open
#include <stdlib.h> //malloc, free

typedef struct	s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	int	*data;
	int bpp;
	int size_l;
	int endianl;
}				t_mlx;
//기본 mlx형태 >>추후에 수정에 들어갈 수 있음

typedef struct	s_scene
{
	int res_x;
	int res_y;
	int res_ex;
	
	double amb_ratio;
	int amb_color;
	int amb_ex;
	//...etc
}				t_scene;
//장면 구조체

typedef struct	s_p3
{
	double x;
	double y;
	double z;
}				t_p3;

typedef struct	s_sp //sphere
{
	t_p3 c;
	double r;
	int inside;
}				t_sp;

union	u_fig
{
	t_sp sp;
	//. pl, sp
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

# define SP 0

void parse(t_mlx *mlx, t_scene *data, t_fig **lst, char **av);

#endif
