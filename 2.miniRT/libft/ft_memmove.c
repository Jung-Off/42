/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 13:18:14 by jji               #+#    #+#             */
/*   Updated: 2020/12/29 19:37:36 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	if (src == dst || len == 0)
		return (dst);
	s = (unsigned char*)src;
	d = dst;
	i = 0;
	if (src > dst)
		while (i < len)
		{
			d[i] = s[i];
			++i;
		}
	else
		while (0 < len)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	return (dst);
}
