/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 12:21:09 by jji               #+#    #+#             */
/*   Updated: 2021/01/04 18:54:22 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	new_t;
	unsigned char	*new_s;
	size_t			i;

	new_s = (unsigned char*)s;
	new_t = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (new_s[i] == new_t)
			return (new_s + i);
		++i;
	}
	return (0);
}
