#include "../includes/split_etc.h"

void split_resolution(t_scene *data, char *str)
{
	/*
	 if(data->res_existence > 0)
		return ; //after >> error
	data->res_ex += 1;
	*/
	data->res_x = rt_atoi(&str);	
	data->res_y = rt_atoi(&str);
}

void split_ambient(t_scene *data, char *str)
{
	/*
	if(data->amb_ex > 0)
		return ; //after >> error
	data->amb_ex += 1;
	*/
	data->amb_ratio = ft_atod(&str);
	
	//ratio 가 0,1사이에 들어와야 된다는 조건	
	data->amb_color = parse_albedo(&str);
}

void split_light(t_scene *data, char *str)
{
	t_light *light;
	t_light *move_light;

	move_light = data->l;

	if (!(light = malloc(sizeof(t_light))))
		return ;
	//free
	if(data->l)
	{	
		while (move_light->next)
			move_light = move_light->next;
		move_light->next = light;
	}
	else
		data->l = light;

	light->position = parse_xyz(&str);
	light->br = ft_atod(&str);
	light->color = parse_albedo(&str);
	light->next = NULL;
}

void split_camera(t_mlx *mlx, t_scene *data, char *str)
{
	t_cam *cam;
	t_cam *move_cam;

	move_cam = mlx->cam;
	if(!(cam = malloc(sizeof(t_cam))))
		return ;
	//free
	if(mlx->cam)
	{
		while(move_cam->next)
			move_cam = move_cam->next;
		move_cam->next = cam;
	}
	else
		mlx->cam = cam;
	//t_scene data를 들고오는 이유 data에다가 camera 갯수가 들어있어서
	//수정가능?
	cam->position = parse_xyz(&str);
	cam->dir_vec = parse_xyz(&str);
	cam->fov = rt_atoi(&str);
	cam->next = NULL;
}
