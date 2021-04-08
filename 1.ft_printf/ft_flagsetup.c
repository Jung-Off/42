/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsetup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:31:40 by jji               #+#    #+#             */
/*   Updated: 2021/02/15 14:52:25 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_lineup_zero(char **p, t_flag *t)
{
	while (**p == '0' || **p == '-')
	{
		if (**p == '-')
			t->minus = 1;
		else if (**p == '0')
			t->zero = 1;
		if (t->minus == 1 && t->zero == 1)
			t->zero = 0;
		(*p)++;
	}
}

void	ft_flag_wp(char **p, t_flag *t, va_list ap)
{
	int	num;

	num = 0;
	if (**p == '*' && (*p)++)
		num = va_arg(ap, int);
	else if (**p == '-' || ft_isdigit(**p))
		num = ft_atoi_moveaddress(p);
	if (t->dot == 1)
		t->pre = num;
	else
	{
		if (num < 0)
		{
			t->wid = num * (-1);
			t->minus = 1;
		}
		else
			t->wid = num;
	}
	if (t->minus == 1 && t->zero == 1)
		t->zero = 0;
}

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
