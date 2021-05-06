
#include "../includes/main.h"

int key_press(int key, t_mlx mlx)
{
	printf("%d\n", key);
	if (key == 53)
		exit(0);
	return (0);
}

int main(int argc, char **argv)
{
	t_mlx 	mlx;
	t_scene data;
	t_fig	*lst;

	//
	t_fig 	*start;
	start = lst;
	parse(&mlx, &data, &lst, argv);
	
	
	camera_create(mlx.cam, &data);

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr,data.res_x, data.res_y, "minirt_test");	
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, data.res_x, data.res_y);
	mlx.data = (int *)mlx_get_data_addr(mlx.img_ptr, &mlx.bpp, &mlx.size_l, &mlx.endian);
	
	make_picture(&mlx, data, lst);

	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, 02, 1L<<0, key_press, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
