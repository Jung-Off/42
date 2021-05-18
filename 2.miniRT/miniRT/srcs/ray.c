/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:26:54 by jji               #+#    #+#             */
/*   Updated: 2021/05/18 12:26:55 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	ray(t_p3 orig, t_p3 dir)
{
	t_ray ray;

	ray.origin = orig;
	ray.dir = vunit(dir);
	return (ray);
}

t_p3	ray_at(t_ray *r, double t)
{
	t_p3	half_line;

	half_line = vscalarmul(r->dir, t);
	half_line = vadd(half_line, r->origin);
	return (half_line);
}

t_p3	ray_color(t_data *data, t_ray *r)
{
	double			t;
	t_p3			n;
	t_hit_record	rec;

	rec.t_min = EPSILON;
	rec.t_max = INFINITY;
	if (hit(data->lst, r, &rec))
		return (phong_lighting(data, r, &rec));
	else
		return (vdefine(1, 1, 1));
}

t_ray	ray_primary(t_scene *scene, double u, double v)
{
	t_ray	ray;

	ray.origin = scene->origin;
	ray.dir.x = scene->l_l_corner.x + u * scene->horizontal.x
		+ v * scene->vertical.x - scene->origin.x;
	ray.dir.y = scene->l_l_corner.y + u * scene->horizontal.y
		+ v * scene->vertical.y - scene->origin.y;
	ray.dir.z = scene->l_l_corner.z + u * scene->horizontal.z
		+ v * scene->vertical.z - scene->origin.z;
	ray.dir = vunit(ray.dir);
	return (ray);
}

t_p3	phong_lighting(t_data *data, t_ray *r, t_hit_record *rec)
{
	t_p3	light_color;
	t_light	*lights;

	light_color = vdefine(0, 0, 0);
	lights = data->scene.light;
	while (lights)
	{
		light_color = vadd(light_color, point_light_get(data, lights, r, rec));
		lights = lights->next;
	}
	light_color = vadd(light_color, data->scene.amb_color);
	return (vmin(vmul(light_color, rec->albedo), vdefine(1, 1, 1)));
}
