/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_fix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:31:48 by jji               #+#    #+#             */
/*   Updated: 2021/02/15 16:14:49 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_max(int i, int j)
{
	return (i > j ? i : j);
}

static int	c_len(int n)
{
	int				count;
	unsigned int	un;

	if (n == 0)
		return (1);
	count = 0;
	un = n;
	if (n < 0)
	{
		count++;
		un = -n;
	}
	while (un > 0)
	{
		un /= 10;
		count++;
	}
	return (count);
}

int			ft_compare(int n, t_flag *t)
{
	int len;

	len = c_len(n);
	len = ((len > t->pre) ? len : t->pre);
	if (t->dot == 1 && t->pre)
	{
		if (len == t->pre && n < 0)
			++len;
	}
	return (len);
}

char		*ft_itoa_fix(int n, t_flag *t)
{
	char			*tmp;
	int				len;
	int				negative;
	unsigned int	un;

	len = ft_compare(n, t);
	if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	negative = 0;
	un = n;
	if (n < 0)
	{
		negative = 1;
		tmp[0] = '-';
		un = -n;
	}
	tmp[len--] = '\0';
	while (len >= (negative ? 1 : 0))
	{
		tmp[len] = un % 10 + '0';
		un /= 10;
		len--;
	}
	return (tmp);
}
