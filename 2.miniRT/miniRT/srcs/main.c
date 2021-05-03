
#include "../includes/main.h"

void pass_comma(char **str)
{
	if (**str == ',')
		(*str)++;
}

int ft_isspace(int c)
{
	if(c >= 9 && c <= 13 || c == 32)
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

	return (p);
}

void ft_newlstadd(t_fig **lst)
{
	t_fig *new;
	t_fig *head;

	head = *lst;
	if (!(new = malloc(sizeof(t_fig))))
		return ;
	//free
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

int rt_atoi(char **str)
{
	int res;
	int minus;

	res = 0;
	minus = 1;

	while(ft_isspace(**str))
		(*str)++;
	if(**str == '-' && (*str)++)
		minus = -1;
	while (ft_isdigit(**str))
		res = res * 10 + (*((*str)++) - '0');
	return (res * minus);
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

void split_sphere(t_fig **lst, char *str)
{
	t_fig *new_list;

	ft_newlstadd(lst);
	new_list = *lst;
	while (new_list->next)
		new_list = new_list->next;
	
	new_list->flag = SP;
	new_list->fig.sp.c = parse_xyz(&str);
	new_list->fig.sp.r = ft_atod(&str) / 2;
	new_list->color = parse_color(&str);
	new_list->next = NULL;
}

void split_plane(t_fig **lst, char *str)
{
	t_fig *new_list;

	ft_newlstadd(lst);
	new_list = *lst;
	while(new_list->next)
		new_list = new_list->next;

	new_list->flag = PL;
	new_list->fig.pl.position = parse_xyz(&str);
	new_list->fig.pl.normal = parse_xyz(&str);
	new_list->fig.pl.color = parse_color(&str);
	new_list->next = NULL;
}

void split_square(t_fig **lst, char *str)
{
	t_fig *new_list;

	ft_newlstadd(lst);
	new_list = *lst;
	while(new_list->next)
		new_list = new_list->next;

	new_list->flag = SQ;
	new_list->fig.sq.sq_c = parse_xyz(&str);
	new_list->fig.sq.normal = parse_xyz(&str);
	new_list->fig.sq.length = ft_atod(&str);
	new_list->fig.sq.color = parse_color(&str);
	new_list->next = NULL;
}

void split_cylinder(t_fig **lst, char *str)
{
	t_fig *new_list;
	ft_newlstadd(lst);
	new_list = *lst;
	while(new_list->next)
		new_list = new_list->next;

	new_list->flag = CY;
	new_list->fig.cy.c = parse_xyz(&str);
	new_list->fig.cy.normal = parse_xyz(&str);
	new_list->fig.cy.r = ft_atod(&str);
	new_list->fig.cy.h = ft_atod(&str);
	new_list->fig.cy.color = parse_color(&str);
	new_list->next = NULL;
}

void split_triangle(t_fig **lst, char *str)
{
	t_fig *new_list;
	ft_newlstadd(lst);
	new_list = *lst;
	while(new_list->next)
		new_list = new_list->next;

	new_list->flag = TR;
	new_list->fig.tr.first = parse_xyz(&str);
	new_list->fig.tr.second = parse_xyz(&str);
	new_list->fig.tr.third = parse_xyz(&str);
	new_list->fig.tr.color = parse_color(&str);
	new_list->next = NULL;
}

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
	data->amb_color = parse_color(&str);
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
	light->color = parse_color(&str);
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

void find_figure(t_mlx *mlx, t_scene *data, t_fig **lst, char *str)
{
	if (*str == 's' && *(str + 1) == 'p')
		split_sphere(lst, str + 2);
	else if (*str == 'R')
		split_resolution(data, str + 1);
	else if (*str == 'A')
		split_ambient(data, str + 1);
	else if (*str == 'l')
		split_light(data, str + 1);
	else if (*str == 'c' && *(str + 1) == 'y') //cy때문에 예외처리
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

int main(int argc, char **argv)
{
	t_mlx 	mlx;
	t_scene data;
	t_fig	*lst;

	//
	t_fig 	*start;
	start = lst;
	parse(&mlx, &data, &lst, argv);

}
