
#include "../includes/main.h"

void ft_newadd(t_fig **lst)
{
	t_fig *new;

	if(!(new = malloc(sizeof(t_fig))))
		return (0);
	new->next = NULL;
	if(lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	else
		*lst = new;
}

void split_sphere(t_fig **lst, char *str)
{
	t_fig *new_list;
	t_fig *head;

	head = *lst;
	ft_newadd(head);
	new_list = *lst;
	while(new_list->next)
		new_list->next;
	
	lst->flag = SP;
	lst->fig.sp.c = parse_xyz(&str);
	
}

void find_figure(t_mlx *mlx, t_scene *data, t_fig **lst, char *str)
{
	if (*str == 's' && *(str + 1) == 'p')
		split_sphere(lst, str);
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

	*lst == NULL;

	if((fd = open(av[1], 0)) == -1)
		exit(1);

	while(get_next_line(fd, &str))
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
