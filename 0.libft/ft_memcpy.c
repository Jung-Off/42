/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 00:10:04 by jji               #+#    #+#             */
/*   Updated: 2021/01/01 01:21:27 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *new_d;
	unsigned char *new_s;
	size_t i;

	i = 0;
	if(!dst && !src)
		return (0);
	new_d = dst;
	new_s = (unsigned char *)src;
	while(i < n)		
	{
		new_d[i] = new_s[i];
		++i;
	}
	return (dst);
}

		
