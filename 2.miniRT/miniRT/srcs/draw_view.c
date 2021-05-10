
#include "../includes/draw_view.h"

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


t_bool in_shadow(t_fig *lst, t_ray light_ray, double light_len)
{
    t_hit_record rec;
    rec.tmin = 0;
    rec.tmax = light_len;
    if(hit(lst, &light_ray, &rec))
        return(TRUE);
    return (FALSE);
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

