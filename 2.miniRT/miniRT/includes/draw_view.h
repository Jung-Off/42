

#ifndef DRAW_VIEW_H
# define DRAW_VIEW_H

#include "main.h"

void        camera_create(t_cam *cam, t_scene *data);
void        make_picture(t_mlx *mlx, t_scene data, t_fig *lst);
t_bool		hit_object(t_fig *lst, t_ray *r, t_hit_record *rec);
t_bool		hit(t_fig *lst, t_ray *r, t_hit_record *rec);
t_bool      in_shadow(t_fig *lst, t_ray light_ray, double light_len);


#endif