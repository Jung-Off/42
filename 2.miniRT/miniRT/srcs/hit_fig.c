
#include "../includes/main.h"

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