#include "../includes/parse_utils.h"

void	pass_comma(char **str)
{
	if (**str == ',')
		(*str)++;
}

int		ft_isspace(int c)
{
	if (c >= 9 && c <= 13 || c == 32)
		return (1);
	else
		return (0);
}

double	ft_atod(char **str)
{
	double	d;
	int		minus;
	int		i;

	d = 0;
	minus = 1;
	i = 1;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-' && (*str)++)
		minus = -1;
	while (ft_isdigit(**str))
		d =  d * 10 + (*((*str)++) - '0');//(*str)++;
	if ((**str) == '.' && (*str)++)
		while (ft_isdigit(**str))
			d += pow(0.1, i++) * (*((*str)++) - '0');//(*str)++;
	return (d * minus);
}

void	ft_newlstadd(t_fig **lst)
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

int		rt_atoi(char **str)
{
	int res;
	int minus;

	res = 0;
	minus = 1;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-' && (*str)++)
		minus = -1;
	while (ft_isdigit(**str))
		res = res * 10 + (*((*str)++) - '0');
	return (res * minus);
}
