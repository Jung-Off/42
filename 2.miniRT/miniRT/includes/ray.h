#ifndef RAY_H
# define RAY_H

#include "main.h"

void        camera_create(t_cam *cam, t_scene *data);
t_ray       ray_primary(t_cam *cam, double u, double v);
t_p3        ray_color(t_ray *r);
void        make_picture(t_mlx *mlx, t_scene data, t_fig *lst);

#endif