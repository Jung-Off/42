
#include "../includes/main.h"

void pass_comma(char **str)
{
	if (**str == ',')
		(*str)++;
}

int ft_isspace(int c)
{
	if(c > 9 && c < 13 || c == 32)
		return (1);
	else
		return (0);
}

double ft_atod(char **str)
{
	double	d;
	int		minus;
	int		i;

	d = 0;
	minus = 1;
	i = 1;
	while(ft_isspace(**str))
		(*str)++;
	if (**str == '-' && (*str)++)
		minus = -1;	
	while(ft_isdigit(**str))
		d =  d * 10 + (*((*str)++) - '0');//(*str)++;
	if ((**str) == '.' && (*str)++)
		while(ft_isdigit(**str))
			d += pow(0.1, i++) * (*((*str)++) - '0');//(*str)++;
	return (d * minus);
}

t_p3 parse_xyz(char **str)
{
	t_p3 p;

	p.x = ft_atod(str); // atod에서 주소를 넘어가도록 하는게 맞지 않나?
	pass_comma(str);
	p.y = ft_atod(str);
	pass_comma(str);
	p.z = ft_atod(str);

	//printf("%lf %lf %lf", p.x, p.y ,p.z);
	return (p);
}

void ft_newadd(t_fig **lst)
{
	t_fig *new;
	t_fig *head;

	head = *lst;
	if (!(new = malloc(sizeof(t_fig))))
		return ;
	new->next = NULL;
	if (head)
	{
		while (head->next)
			head = head->next;
		head->next = new;
	}
	else
		*lst = new;
}

void split_sphere(t_fig **lst, char *str)
{
	t_fig *new_list;

	ft_newadd(lst);
	new_list = *lst;
	while (new_list->next)
		new_list = new_list->next;
	
	new_list->flag = SP;
	new_list->fig.sp.c = parse_xyz(&str);
}

void find_figure(t_mlx *mlx, t_scene *data, t_fig **lst, char *str)
{
	if (*str == 's' && *(str + 1) == 'p')
		split_sphere(lst, str + 2);
	//..etc
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

	if ((fd = open(av[1], 0)) == -1)
		exit(1);

	while (get_next_line(fd, &str))
		before_parsing(mlx, data, lst, str);
	
	free(str);
	str = 0;
}

int main(int argc, char **argv)
{
	t_mlx 	mlx;
	t_scene data;
	t_fig	*lst;

	parse(&mlx, &data, &lst, argv);
}
