#include "../includes/ray.h"

t_ray	ray_primary(t_cam *cam, double u, double v)
{
	t_ray ray;

	ray.orig = cam->origin;
	ray.dir.x = cam->l_l_corner.x + u * cam->horizontal.x
		+ v * cam->vertical.x - cam->origin.x;
	ray.dir.y = cam->l_l_corner.y + u * cam->horizontal.y
		+ v * cam->vertical.y - cam->origin.y;
	ray.dir.z = cam->l_l_corner.z + u * cam->horizontal.z
		+ v * cam->vertical.z - cam->origin.z;
	ray.dir = vunit(ray.dir);
	return (ray);
}

t_ray	ray(t_p3 orig, t_p3 dir)
{
	t_ray ray;

	ray.orig = orig;
	ray.dir = vunit(dir);
	return (ray);
}

t_p3	ray_at(t_ray *r, double t)
{
	t_p3 half_line;

	half_line = vscalarmul(r->dir, t);
	half_line = vadd(half_line, r->orig);
	return (half_line);
}

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = vdot(r->dir, rec->normal) < 0;
	rec->normal = (rec->front_face) ? rec->normal : vscalarmul(rec->normal, -1);
}

t_p3	ray_color(t_scene data, t_ray *r, t_fig *lst)
{
	double			t;
	t_p3			n;
	t_hit_record	rec;

	rec.tmin = EPSILION;
	rec.tmax = INFINITY;
	if (hit(lst, r, &rec))
		return (phong_lighting(data, r, &rec, lst));
	else
	{
		t = 0.5 * (r->dir.y + 1.0);
		return (vadd(vscalarmul(vdefine(1, 1, 1), 1.0 - t),
					vscalarmul(vdefine(0.5, 0.7, 1.0), t)));
	}
}
