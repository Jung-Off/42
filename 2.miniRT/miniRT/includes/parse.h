#ifndef PARSE_H
# define PARSE_H

#include "main.h"

void before_parsing(t_mlx *mlx, t_scene *data, t_fig **lst, char *str);
void parse(t_mlx *mlx, t_scene *data, t_fig **lst, char **av);
t_p3 parse_xyz(char **str);
int parse_color(char **str);
void find_figure(t_mlx *mlx, t_scene *data, t_fig **lst, char *str);

#endif