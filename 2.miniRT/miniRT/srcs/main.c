
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

int		key_press(int key, t_main *s)
{
	if (key == 53)
		exit(0);
	else if(key == 124)
	{
		s->mlx.cam = s->mlx.cam->next;
		printf("%p\n", s->mlx.cam);
		make_picture(s);
		mlx_put_image_to_window(s->mlx.mlx_ptr, s->mlx.win_ptr, s->mlx.img_ptr, 0, 0);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_main	s;

	parse(&s.mlx, &s.data, &s.lst, argv);
	camera_create(s.mlx.cam, &s.data);
	s.mlx.mlx_ptr = mlx_init();
	s.mlx.win_ptr = mlx_new_window(s.mlx.mlx_ptr,
			s.data.res_x, s.data.res_y, "minirt_test");	
	s.mlx.img_ptr = mlx_new_image(s.mlx.mlx_ptr, s.data.res_x, s.data.res_y);
	s.mlx.data = (int *)mlx_get_data_addr(s.mlx.img_ptr,
			&s.mlx.bpp, &s.mlx.size_l, &s.mlx.endian);

	t_cam	*p;

	p = s.mlx.cam;
	while (p->next)
		p = p->next;
	p->next = s.mlx.cam;

	make_picture(&s);
	mlx_put_image_to_window(s.mlx.mlx_ptr, s.mlx.win_ptr, s.mlx.img_ptr, 0, 0);
	mlx_hook(s.mlx.win_ptr, 02, 1L << 0, key_press, &s);
	mlx_loop(s.mlx.mlx_ptr);

	return (0);
}
