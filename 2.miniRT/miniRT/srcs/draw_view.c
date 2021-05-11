
#include "../includes/draw_view.h"

void	camera_create(t_cam *cam, t_scene *data)
{
	double aspect_ratio;
	double theta = degrees_to_radians(cam->fov);
	double h = tan(theta / 2);


	aspect_ratio = (double)data->res_x / (double)data->res_y;
	data->viewport_h = 2.0 * h;
	data->viewport_w = aspect_ratio * data->viewport_h;
	data->focal_length = 1.0;
	data->origin = cam->lookfrom;

	t_p3 w = vunit(vsubstract(data->origin,cam->lookat));
	t_p3 u = vunit(vcross(vdefine(0, 1, 0), w)); //예외처리
	t_p3 v = vcross(w, u);

	data->horizontal = vscalarmul(u, data->viewport_w);
	data->vertical = vscalarmul(v, data->viewport_h);
	data->l_l_corner.x = data->origin.x
		- (data->horizontal.x / 2) - (data->vertical.x / 2) - w.x;
	data->l_l_corner.y = data->origin.y
		- (data->horizontal.y / 2) - (data->vertical.y / 2) - w.y;
	data->l_l_corner.z = data->origin.z
		- (data->horizontal.z / 2) - (data->vertical.z / 2) - w.z;
	data->amb_color = vscalarmul(data->amb_color, data->amb_ratio);
}

t_bool	in_shadow(t_fig *lst, t_ray light_ray, double light_len)
{
	t_hit_record rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(lst, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

t_bool	hit_obj(t_fig *lst, t_ray *r, t_hit_record *rec)
{
	t_bool			hit_result;

	hit_result = FALSE;
	if (lst->flag == SP)
		hit_result = hit_sphere(lst, r, rec);
	return (hit_result);
}

t_bool	hit(t_fig *lst, t_ray *r, t_hit_record *rec)
{
	t_bool			hit_fig;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_fig = FALSE;
	while (lst)
	{
		if (hit_obj(lst, r, &temp_rec))
		{
			hit_fig = TRUE;
			temp_rec.tmax = temp_rec.oc_r;
			*rec = temp_rec;
		}
		lst = lst->next;
	}
	return (hit_fig);
}

void	make_picture(t_mlx *mlx, t_scene data, t_fig *lst)
{
	t_ray		ray;
	t_p3		color;
	t_matrix	m;

	m.y = 0;
	while (m.y < data.res_y)
	{
		m.x = 0;
		while (m.x < data.res_x)
		{
			m.u = (double)m.x / (data.res_x - 1);
			m.v = (data.res_y - (double)m.y - 1) / (data.res_y - 1);
			ray = ray_primary(&data, m.u, m.v);
			color = ray_color(data, &ray, lst);
			color.x = (int)(color.x * 255);
			color.y = (int)(color.y * 255);
			color.z = (int)(color.z * 255);
			mlx->data[m.y * data.res_x + m.x] =
				mlx_get_color_value(mlx->mlx_ptr, color.x * 256 * 256
						+ color.y * 256 + color.z);
			++m.x;
		}
		++m.y;
	}
}

