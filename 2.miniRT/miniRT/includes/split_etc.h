#ifndef SPLIT_ETC_H
# define SPLIT_ETC_H

# include "main.h"

void	split_resolution(t_scene *data, char *str);
void	split_ambient(t_scene *data, char *str);
void	split_light(t_scene *data, char *str);
void	split_camera(t_mlx *mlx, t_scene *data, char *str);

#endif
