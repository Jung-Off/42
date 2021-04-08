/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:35:44 by jji               #+#    #+#             */
/*   Updated: 2021/01/04 19:03:14 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *b, int c, size_t n)
{
	unsigned char *new_b;
	unsigned char new_c;
	size_t i;

	new_b = (unsigned char *)b;
	new_c = c;
	i = 0;

	while(i < n)
	{
		if(new_b[i] == new_c)
			return(new_b+i);
		++i;
	}
	return (0);
}
