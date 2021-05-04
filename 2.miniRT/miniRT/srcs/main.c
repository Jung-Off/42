
#include "../includes/main.h"


int main(int argc, char **argv)
{
	t_mlx 	mlx;
	t_scene data;
	t_fig	*lst;

	//
	t_fig 	*start;
	start = lst;
	parse(&mlx, &data, &lst, argv);


	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, data.res_x, data.res_y, "minirt_test");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, data.res_x, data.res_y);
	mlx.data = mlx_get_data_addr(mlx.img_ptr, &mlx.bpp, &mlx.size_l, &mlx.endian);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);

	mlx_loop(mlx.mlx_ptr);
	return (0);
}
