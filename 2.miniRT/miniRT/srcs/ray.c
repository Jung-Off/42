#include "../includes/ray.h"

void camera_create(t_cam *cam, t_scene *data)
{
	double aspect_ratio = (double)data->res_x / (double)data->res_y;

	cam->viewport_h = 2.0;
	cam->viewport_w = aspect_ratio * cam->viewport_h;
	cam->focal_length = 1.0;

	cam->origin = cam->position; //vdefine(0.0, 0.0, 0.0);
	cam->horizontal = vdefine(cam->viewport_w, 0.0, 0.0);
	cam->vertical = vdefine(0.0, cam->viewport_h, 0.0);

	cam->l_l_corner.x = cam->origin.x - (cam->horizontal.x / 2) - (cam->vertical.x / 2) - 0;
	cam->l_l_corner.y = cam->origin.y - (cam->horizontal.y / 2) - (cam->vertical.y / 2) - 0;
	cam->l_l_corner.z = cam->origin.z - (cam->horizontal.z / 2) - (cam->vertical.z / 2) - cam->focal_length;

	data->amb_color = vscalarmul(data->amb_color, data->amb_ratio);
}

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

t_bool hit_sphere(t_fig *lst, t_ray *r, t_hit_record *rec)
{
	t_p3 oc;
	double a;
	double half_b;
	double c;
	double discriminant;
	double sqrtd;
	double root;

	oc = vsubstract(r->orig, lst->fig.sp.c);
	a = vdot(r->dir, r->dir);
	half_b = vdot(oc, r->dir);
	c = vdot(oc, oc) - pow(lst->fig.sp.r, 2);
	discriminant = half_b * half_b - a * c;

	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->oc_r = root;
	rec->p_meet = ray_at(r, root);
	rec->normal = vscalardiv(vsubstract(rec->p_meet, lst->fig.sp.c), lst->fig.sp.r);
	rec->albedo = lst->albedo;
	set_face_normal(r, rec);
	return (TRUE);
}

t_bool hit_obj(t_fig *lst, t_ray *r, t_hit_record *rec)
{
	t_bool hit_result;

	hit_result = FALSE;
	if (lst->flag == SP)
		hit_result = hit_sphere(lst, r, rec);
	return (hit_result);
}

t_bool hit(t_fig *lst, t_ray *r, t_hit_record *rec)
{
	t_bool hit_fig;
	t_hit_record temp_rec;

	temp_rec = *rec;
	hit_fig = FALSE;
	while (lst)
	{
		if (hit_obj(lst, r, &temp_rec))
		{
			//
			hit_fig = TRUE;
			temp_rec.tmax = temp_rec.oc_r;
			*rec = temp_rec;
		}
		lst = lst->next;
	}
	return (hit_fig);
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

t_p3	point_light_get(t_scene data, t_ray *r, t_hit_record *rec, t_fig *lst)
{
	t_p3	diffuse;
	t_p3	light_dir;
	double	d_weight;

	double	light_len;
	t_p3	light_ray;

	t_p3	specular;
	t_p3	view_dir;
	t_p3	reflect_dir;
	double	s_weight;
	double	shine;
	double	spec;

	light_dir = vsubstract(data.l->position, rec->p_meet);
	light_len = vlen(light_dir);
	light_ray = ray(vadd(rec->p_meet, vscalarmul(rec->normal, EPSILION)), light_dir);

	if (in_shadow(lst, light_ray, light_len))
		return (vdefine(0, 0, 0));

	light_dir = vunit(light_dir);
	//light_dir = vunit(vsubstract(data.l->position, rec->p_meet));
	d_weight = fmax(vdot(rec->normal, light_dir), 0.0);
	diffuse = vscalarmul(rec->albedo, d_weight);

	view_dir = vunit(vscalarmul(r->dir, -1));
	reflect_dir = reflect(vscalarmul(light_dir, -1), rec->normal);
	shine = 64;
	s_weight = 0.5;
	spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), shine);
	specular = vscalarmul(vscalarmul(rec->albedo, s_weight), spec);
	//return (vadd(diffuse, specular));

	return (vscalarmul(vadd(vadd(data.amb_color, diffuse), specular), data.l->br * LUMEN));
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
		return (vmin(point_light_get(data, r, &rec, lst), vdefine(1, 1, 1)));
	}
	else
	{
		t = 0.5 * (r->dir.y + 1.0);
		return (vadd(vscalarmul(vdefine(1, 1, 1), 1.0 - t), vscalarmul(vdefine(0.5, 0.7, 1.0), t)));
	}
}

void make_picture(t_mlx *mlx, t_scene data, t_fig *lst)
{
	t_ray ray;
	t_p3 color;

	int y = 0;
	int x;
	double u, v;
	while (y < data.res_y)
	{
		x = 0;
		while (x < data.res_x)
		{
			u = (double)x / (data.res_x - 1);
			v = (data.res_y - (double)y - 1) / (data.res_y - 1);
			ray = ray_primary(mlx->cam, u, v);
			color = ray_color(data, &ray, lst);

			color.x = (int)(color.x * 255);
			color.y = (int)(color.y * 255);
			color.z = (int)(color.z * 255);
			mlx->data[y * data.res_x + x] = mlx_get_color_value(mlx->mlx_ptr, color.x * 256 * 256 + color.y * 256 + color.z);
			++x;
		}
		++y;
	}
}
