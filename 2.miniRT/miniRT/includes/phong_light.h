#ifndef PHONG_LIGHT_H
# define PHONG_LIGHT_H

# include "main.h"

t_p3 diffuse(t_light *light, t_hit_record *rec);
t_p3 reflect(t_p3 v, t_p3 n);
t_p3 specular(t_light *light, t_ray *r, t_hit_record *rec);
t_p3 point_light_get(t_scene data, t_light *light,
		t_ray *r, t_hit_record *rec, t_fig *lst);
t_p3 phong_lighting(t_scene data, t_ray *r, t_hit_record *rec, t_fig *lst);

#endif
