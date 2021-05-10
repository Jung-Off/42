#include "../includes/ray.h"

t_ray ray_primary(t_cam *cam, double u, double v)
{
	t_ray ray;

	ray.orig = cam->origin;

	//ray.dir = vunit((vsubstract(vadd(vadd(cam->l_l_corner, vscalarmul(cam->horizontal, u)), vscalarmul(cam->vertical, v)), cam->origin)));
	ray.dir.x = cam->l_l_corner.x + u * cam->horizontal.x + v * cam->vertical.x - cam->origin.x;
	ray.dir.y = cam->l_l_corner.y + u * cam->horizontal.y + v * cam->vertical.y - cam->origin.y;
	ray.dir.z = cam->l_l_corner.z + u * cam->horizontal.z + v * cam->vertical.z - cam->origin.z;
	ray.dir = vunit(ray.dir);
	return (ray);
}

t_ray ray(t_p3 orig, t_p3 dir)
{
	t_ray ray;
	ray.orig = orig;
	ray.dir = vunit(dir);
	return (ray);
}

t_p3 ray_at(t_ray *r, double t)
{
	t_p3 half_line;
	half_line = vscalarmul(r->dir, t);
	half_line = vadd(half_line, r->orig);
	return (half_line);
}

void set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = vdot(r->dir, rec->normal) < 0;
	rec->normal = (rec->front_face) ? rec->normal : vscalarmul(rec->normal, -1);
}



// t_p3	diffuse(t_light *light, t_hit_record *rec)
// {
// 	t_p3	diffuse;
// 	t_p3	light_dir;
// 	double	d_weight;

// 	light_dir = vunit(vsubstract(light->position, rec->p_meet));
// 	d_weight = fmax(vdot(rec->normal, light_dir), 0.0);
// 	diffuse = vscalarmul(rec->albedo, d_weight);
// 	return(diffuse);
// }

t_p3	reflect(t_p3 v, t_p3 n)
{
	return (vsubstract(v, vscalarmul(n, vdot(v, n) * 2)));
}

// t_p3	specular(t_light *light, t_ray *r, t_hit_record *rec)
// {
// 	t_p3	specular;
// 	t_p3	light_dir;
// 	t_p3	view_dir;
// 	t_p3	reflect_dir;
// 	double	s_weight;
// 	double	shine;
// 	double	spec;

// 	light_dir = vunit(vsubstract(light->position, rec->p_meet));
// 	view_dir = vunit(vscalarmul(r->dir, -1));
// 	reflect_dir = reflect(vscalarmul(light_dir, -1), rec->normal);
// 	shine = 64;
// 	s_weight = 0.5;
// 	spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), shine);
// 	specular = vscalarmul(vscalarmul(rec->albedo, s_weight), spec);
// 	return (specular);
// }

t_p3	point_light_get(t_scene data, t_light *light, t_ray *r, t_hit_record *rec, t_fig *lst)
{
	t_p3	diffuse;
	t_p3	light_dir;
	double	d_weight;

	double	light_len;
	t_ray	light_ray;

	t_p3	specular;
	t_p3	view_dir;
	t_p3	reflect_dir;
	double	s_weight;
	double	shine;
	double	spec;

	light_dir = vsubstract(light->position, rec->p_meet);
	light_len = vlen(light_dir);
	light_ray = ray(vadd(rec->p_meet, vscalarmul(rec->normal, EPSILION)), light_dir);

	if (in_shadow(lst, light_ray, light_len))
		return (vdefine(0, 0, 0));

	light_dir = vunit(light_dir);
	//light_dir = vunit(vsubstract(light->position, rec->p_meet));
	d_weight = fmax(vdot(rec->normal, light_dir), 0.0);
	diffuse = vscalarmul(rec->albedo, d_weight);

	view_dir = vunit(vscalarmul(r->dir, -1));
	reflect_dir = reflect(vscalarmul(light_dir, -1), rec->normal);
	shine = 64;
	s_weight = 0.5;
	spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), shine);
	specular = vscalarmul(vscalarmul(rec->albedo, s_weight), spec);
	//return (vadd(diffuse, specular));

	return (vscalarmul(vadd(vadd(data.amb_color, diffuse), specular), light->br * LUMEN));
}

t_p3	phong_lighting(t_scene data, t_ray *r, t_hit_record *rec, t_fig *lst)
{
	t_p3	light_color;
	t_light	*lights;

	light_color = vdefine(0, 0, 0);
	lights = data.l;
	while (lights)
	{
		light_color = vadd(light_color, point_light_get(data, lights, r, rec, lst));
		//printf("%lf %lf %lf\n", light_color.x, light_color.y, light_color.z);
		lights = lights->next;
	}
	light_color = vadd(light_color, data.amb_color);
	return (vmin(vmul(light_color, rec->albedo), vdefine(1, 1, 1)));
}

t_p3 ray_color(t_scene data, t_ray *r, t_fig *lst)
{
	double t;
	t_p3 n;
	t_hit_record rec;

	rec.tmin = EPSILION;
	rec.tmax = INFINITY;

	double	light_ratio;
	if (hit(lst, r, &rec))
	{
		//data.l->br *= LUMEN;
		//return (vmin(vscalarmul(vadd(vadd(data.amb_color, diffuse(data.l, &rec)), specular(data.l, r, &rec)), data.l->br * LUMEN), vdefine(1, 1, 1)));
		//return (vmin(point_light_get(data, r, &rec, lst), vdefine(1, 1, 1)));
		return (phong_lighting(data, r, &rec, lst));
	}
	else
	{
		t = 0.5 * (r->dir.y + 1.0);
		return (vadd(vscalarmul(vdefine(1, 1, 1), 1.0 - t), vscalarmul(vdefine(0.5, 0.7, 1.0), t)));
	}
}