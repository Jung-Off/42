/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:34:24 by jji               #+#    #+#             */
/*   Updated: 2021/03/29 18:47:23 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int		ft_atoi_moveaddress(char **str)
{
	long long	num;
	int			sign;

	sign = 1;
	while (**str == '\t' || **str == '\n' || **str == '\v' || **str == '\f'
			|| **str == '\r' || **str == ' ')
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	num = 0;
	while (**str >= '0' && **str <= '9')
	{
		num = num * 10 + (**str - '0');
		if (num > 2147483647 && sign == 1)
			return (-1);
		if (num > 2147483648 && sign == -1)
			return (0);
		(*str)++;
	}
	return (num * sign);
}


void save_cycle(char **line, t_shape *shape)
{
	shape->cycle.x = ft_atoi_moveaddress(line);
	shape->cycle.y = ft_atoi_moveaddress(line);
	shape->cycle.z = ft_atoi_moveaddress(line);

	shape->cycle.r =ft_atoi_moveaddress(line);

	shape->cycle.red = ft_atoi_moveaddress(line);
	shape->cycle.green = ft_atoi_moveaddress(line);
	shape->cycle.blue = ft_atoi_moveaddress(line);
}

void make_struct(char **line, t_shape *shape)
{
	if (ft_strnstr(*line ,"sp", ft_strlen("sp")))
		save_cycle(line, shape);

	printf("%lf  %lf", shape->cycle.x, shape->cycle.blue);
}
