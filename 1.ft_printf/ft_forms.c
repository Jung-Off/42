/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:24:12 by jji               #+#    #+#             */
/*   Updated: 2021/02/16 16:29:06 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			format_s(t_flag *t, char *str)
{
	char	*str_re;
	int		i;

	if (str == 0)
		str = "(null)";
	if (t->dot && t->pre >= 0 && t->pre < (int)ft_strlen(str))
		str_re = ft_substr(str, 0, t->pre);
	else
		str_re = ft_strdup(str);
	i = (t->minus == 1 ? ft_putnum(t, str_re) : ft_putblank(t, str_re));
	i += (t->minus == 0 ? ft_putnum(t, str_re) : ft_putblank(t, str_re));
	free(str_re);
	return (i);
}

static void	ft_write(t_flag t)
{
	char c;

	c = (t.zero ? '0' : ' ');
	while (--t.wid)
		write(1, &c, 1);
}

int			format_c(t_flag *t, int c)
{
	if (t->wid > 1)
	{
		if (t->zero)
		{
			ft_write(*t);
			write(1, &c, 1);
		}
		else if (!t->minus)
		{
			ft_write(*t);
			write(1, &c, 1);
		}
		else
		{
			write(1, &c, 1);
			ft_write(*t);
		}
	}
	else
	{
		write(1, &c, 1);
		t->wid = 1;
	}
	return (t->wid);
}
