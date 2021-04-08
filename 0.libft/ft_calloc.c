/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:14:08 by jji               #+#    #+#             */
/*   Updated: 2021/01/04 20:42:31 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char *tmp;
	size_t i;

	i = 0;
	if(!(tmp = (unsigned char*)malloc(nmemb * size)))
		return (0);
	while(i < nmemb * size)
	{
		tmp[i] = 0;
		++i;
	}
	return (tmp);
}
