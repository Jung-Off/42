/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:22:29 by jji               #+#    #+#             */
/*   Updated: 2021/05/18 12:22:30 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double	degrees_to_radians(int a)
{
	double res;

	res = (double)a * M_PI / 180;
	return (res);
}

int		rt_atoi(char **str)
{
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	while (ft_isspace(**str))
		*str += 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1;
		*str += 1;
	}
	while (ft_isdigit(**str))
	{
		num *= 10;
		num += (*(*str)++ - '0');
	}
	return (num * sign);
}

double	rt_atof(char **str)
{
	int			sign;
	int			n;
	double		num;

	sign = 1;
	num = 0;
	n = -1;
	while (ft_isspace(**str))
		*str += 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1;
		*str += 1;
	}
	while (ft_isdigit(**str))
		num = num * 10 + (*(*str)++ - '0');
	if (**str == '.' && (*str)++)
		while (ft_isdigit(**str))
			num += ((*(*str)++ - '0') * pow(10, n--));
	return (num * sign);
}

t_p3	rt_ato3(char **str)
{
	t_p3	p;

	while (ft_isspace(**str))
		*str += 1;
	p.x = rt_atof(str);
	comma(str);
	p.y = rt_atof(str);
	comma(str);
	p.z = rt_atof(str);
	return (p);
}

t_p3	rt_albedo(char **str)
{
	t_p3 p;

	p.x = rt_atof(str) / 255.0;
	check_values(p.x, 0, 1, "Color");
	comma(str);
	p.y = rt_atof(str) / 255.0;
	check_values(p.y, 0, 1, "Color");
	comma(str);
	p.z = rt_atof(str) / 255.0;
	check_values(p.z, 0, 1, "Color");
	return (p);
}
