#ifndef MAIN_H
# define MAIN_H

# include "get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"

# define SP 0
# define PL 1
# define SQ 2
# define TR 3
# define CY 4
# define LUMEN 3
# define FALSE 0
# define TRUE 1
# define EPSILION 1e-6

# include "structure.h"
# include "parse_utils.h"
# include "parse.h"
# include "split_etc.h"
# include "split_figure.h"
# include "vec_operation.h"
# include "ray.h"
# include "vec_mul.h"
# include "vec_utils.h"
# include "draw_view.h"
# include "hit_fig.h"
# include "phong_light.h"

void	parse(t_mlx *mlx, t_scene *data, t_fig **lst, char **av);
void	find_figure(t_mlx *mlx, t_scene *data, t_fig **lst, char *str);
int		key_press(int key, t_mlx mlx);

#endif
