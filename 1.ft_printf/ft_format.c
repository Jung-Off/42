/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:52:14 by jji               #+#    #+#             */
/*   Updated: 2021/06/09 17:33:59 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putzero(t_flag *t, char *str_d)
{
	int gap;
	int dup;

	gap = t->wid - ft_strlen(str_d);
	dup = gap;
	if (t->zero == 1)
	{
		if (!t->dot)
		{
			while (dup-- > 0)
				write(1, "0", 1);
			if (gap < 0)
				gap = 0;
			return (gap);
		}
		else if (t->dot && t->pre < 0)
		{
			while (dup-- > 0)
				write(1, "0", 1);
			if (gap < 0)
				gap = 0;
			return (gap);
		}
	}
	return (0);
}

int		ft_putblank(t_flag *t, char *str_d)
{
	int gap;
	int num;

	gap = t->wid - (int)ft_strlen(str_d);
	if (gap < 0)
		gap = 0;
	else if (t->zero)
	{
		if (!t->dot)
			gap = 0;
		else if (t->dot && t->pre < 0)
			gap = 0;
	}
	num = gap;
	while (gap--)
		write(1, " ", 1);
	return (num);
}

int		ft_putnum(t_flag *t, char *str_d)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (str_d[0] == '-' && ++str_d)
	{
		write(1, "-", 1);
		++i;
		++j;
	}
	i = ft_putzero(t, str_d - j);
	write(1, str_d, ft_strlen(str_d));
	return (i + j + ft_strlen(str_d));
}

int		ft_allblank(t_flag *t)
{
	int i;

	i = t->wid;
	while (i--)
		write(1, " ", 1);
	return (t->wid);
}

int		format_d(t_flag *t, int d)
{
	char	*str_d;
	int		i;

	if (t->dot == 1 && t->pre == 0 && d == 0)
		return (ft_allblank(t));
	str_d = ft_itoa_fix(d, t);
	i = (t->minus == 1 ? ft_putnum(t, str_d) : ft_putblank(t, str_d));
	i += (t->minus == 0 ? ft_putnum(t, str_d) : ft_putblank(t, str_d));
	free(str_d);
	return (i);
}
