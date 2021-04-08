/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 21:25:59 by jji               #+#    #+#             */
/*   Updated: 2021/01/04 21:36:22 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t n)
{
	unsigned char *new_b1;
	unsigned char *new_b2;
	size_t i;

	new_b1 = (unsigned char *)b1;
	new_b2 = (unsigned char *)b2;

	i = 0;
	while(i < n)
	{
		if(new_b1[i] != new_b2[i])
			return (new_b1[i] - new_b2[i]);
		++i;
	}
	return (0);
}
