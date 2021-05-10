#ifndef RAY_H
# define RAY_H

#include "main.h"

void        camera_create(t_cam *cam, t_scene *data);
t_ray       ray_primary(t_cam *cam, double u, double v);
t_p3        ray_color(t_scene data, t_ray *r, t_fig *lst);
void        make_picture(t_mlx *mlx, t_scene data, t_fig *lst);
t_bool      hit_sphere(t_fig *lst, t_ray *r, t_hit_record *rec);
t_bool		hit_object(t_fig *lst, t_ray *r, t_hit_record *rec);
t_bool		hit(t_fig *lst, t_ray *r, t_hit_record *rec);
t_p3        ray_at(t_ray *r, double t);
t_ray       ray(t_p3, t_p3 dir);
void        set_face_normal(t_ray *r, t_hit_record *rec);

#endif