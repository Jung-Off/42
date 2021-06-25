/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 20:26:54 by jji               #+#    #+#             */
/*   Updated: 2020/12/30 02:33:16 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char		*ft_itoa(int n)
{
	char			*tmp;
	int				len;
	int				negative;
	unsigned int	un;

	len = c_len(n);
	if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	tmp[len--] = '\0';
	negative = 0;
	un = n;
	if (n < 0)
	{
		negative = 1;
		tmp[0] = '-';
		un = -n;
	}
	while (len >= (negative ? 1 : 0))
	{
		tmp[len] = un % 10 + '0';
		un /= 10;
		len--;
	}
	return (tmp);
}
