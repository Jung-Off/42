#include "../includes/split_figure.h"

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
	new_list->albedo = parse_albedo(&str);
	//new_list->fig.sp.color = parse_color(&str);
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
	new_list->albedo = parse_albedo(&str);
	//new_list->fig.pl.color = parse_color(&str);
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
	new_list->albedo = parse_albedo(&str);
	//new_list->fig.sq.color = parse_color(&str);
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
	new_list->albedo = parse_albedo(&str);
	//new_list->fig.cy.color = parse_color(&str);
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
	new_list->albedo = parse_albedo(&str);
	//new_list->fig.tr.color = parse_color(&str);
	new_list->next = NULL;
}