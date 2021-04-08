/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 01:21:35 by jji               #+#    #+#             */
/*   Updated: 2021/01/01 01:35:01 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *new_d;
	unsigned char *new_s;
	unsigned char new_c;
	size_t i;

	i = 0;
	new_d =dst;
	new_s =(unsigned char*)src;
	new_c = c;
	while(i < n)
	{
		new_d[i] = new_s[i];
		if(new_s[i] == new_c)
			return(dst + (i + 1));
		++i;
	}
	return (0);
}
