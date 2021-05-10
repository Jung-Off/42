#include "../includes/parse.h"

t_p3 parse_xyz(char **str)
{
	t_p3 p;

	p.x = ft_atod(str); // atod에서 주소를 넘어가도록 하는게 맞지 않나?
	pass_comma(str);
	p.y = ft_atod(str);
	pass_comma(str);
	p.z = ft_atod(str);

	return (p);
}

t_p3 parse_albedo(char **str)
{
	t_p3 p;

	p.x = ft_atod(str) / 255.0; // atod에서 주소를 넘어가도록 하는게 맞지 않나?
	pass_comma(str);
	p.y = ft_atod(str) / 255.0;
	pass_comma(str);
	p.z = ft_atod(str) / 255.0;

	return (p);
}

int parse_color(char **str)
{
	int r;
	int g;
	int b;

	r = rt_atoi(str);
	pass_comma(str);
	g = rt_atoi(str);
	pass_comma(str);
	b = rt_atoi(str);
	return (r * pow(256,2) + g * pow(256, 1) + b);
}

void before_parsing(t_mlx *mlx, t_scene *data, t_fig **lst, char *str)
{
	/*	if (*str == '#' || *str == 0)
	 		return ;
	 	else
		*/
	find_figure(mlx, data, lst, str);
}

void parse(t_mlx *mlx, t_scene *data, t_fig **lst, char **av)
{
	char	*str;
	int		fd;

	*lst = NULL;
	data->l = NULL;
	mlx->cam = NULL;
//	data->res_ex = 0;
//	data->amb_ex = 0;

	if ((fd = open(av[1], 0)) == -1)
		exit(1);
//readonly == 0
	while (get_next_line(fd, &str))
		before_parsing(mlx, data, lst, str);
	
	free(str);
	str = 0;
}