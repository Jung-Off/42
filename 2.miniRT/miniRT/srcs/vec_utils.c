#include "../includes/vec_utils.h"

t_p3	vmul(t_p3 a, t_p3 b)
{
	t_p3	v;

	v.x = a.x * b.x;
	v.y = a.y * b.y;
	v.z = a.z * b.z;
	return (v);
}

double	vlen(t_p3 a)
{
	double len;

	len = a.x * a.x + a.y * a.y + a.z * a.z;
	len = sqrt(len);
	return (len);
}

t_p3	color_add(t_p3 a, t_p3 b)
{
	t_p3	v;

	v.x = fmin(a.x + b.x, 1.0);
	v.y = fmin(a.y + b.y, 1.0);
	v.z = fmin(a.z + b.z, 1.0);
	return (v);
}

t_p3	vunit(t_p3 a)
{
	return (vscalardiv(a, vlen(a)));
}

t_p3	vmin(t_p3 a, t_p3 b)
{
	if (a.x > b.x)
		a.x = b.x;
	if (a.y > b.y)
		a.y = b.y;
	if (a.z > b.z)
		a.z = b.z;
	return (a);
}
