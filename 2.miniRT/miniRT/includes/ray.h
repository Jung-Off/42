#ifndef RAY_H
# define RAY_H

#include "main.h"


t_ray       ray_primary(t_cam *cam, double u, double v);
t_p3        ray_color(t_scene data, t_ray *r, t_fig *lst);
t_p3        ray_at(t_ray *r, double t);
t_ray       ray(t_p3, t_p3 dir);
void        set_face_normal(t_ray *r, t_hit_record *rec);

#endif
