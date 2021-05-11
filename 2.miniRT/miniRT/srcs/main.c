
#include "../includes/main.h"

void	find_figure(t_mlx *mlx, t_scene *data, t_fig **lst, char *str)
{
	if (*str == 's' && *(str + 1) == 'p')
		split_sphere(lst, str + 2);
	else if (*str == 'R')
		split_resolution(data, str + 1);
	else if (*str == 'A')
		split_ambient(data, str + 1);
	else if (*str == 'l')
		split_light(data, str + 1);
	else if (*str == 'c' && *(str + 1) == 'y')
		split_cylinder(lst, str + 2);
	else if (*str == 'p' && *(str + 1) == 'l')
		split_plane(lst, str + 2);
	else if (*str == 's' && *(str + 1) == 'q')
		split_square(lst, str + 2);
	else if (*str == 'c')
		split_camera(mlx, data, str + 1);
	else if (*str == 't' && *(str + 1) == 'r')
		split_triangle(lst, str + 2);
}

int		key_press(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(0);
	else if(key == 124)
	{
		mlx->cam = mlx->cam->next;
		printf("%p\n", mlx->cam);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;
	t_scene data;
	t_fig	*lst;

	parse(&mlx, &data, &lst, argv);
	camera_create(mlx.cam, &data);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr,
			data.res_x, data.res_y, "minirt_test");	
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, data.res_x, data.res_y);
	mlx.data = (int *)mlx_get_data_addr(mlx.img_ptr,
			&mlx.bpp, &mlx.size_l, &mlx.endian);

	t_cam	*p;

	p = mlx.cam;
	while (p->next)
		p = p->next;
	p->next = mlx.cam;

	make_picture(&mlx, data, lst);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, 02, 1L << 0, key_press, &mlx);
	mlx_loop(mlx.mlx_ptr);

	return (0);
}
