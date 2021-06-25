/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:59:16 by jji               #+#    #+#             */
/*   Updated: 2020/12/23 20:33:34 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char *tmp;

	tmp = (unsigned char *)ptr;
	while (num)
	{
		*tmp = value;
		num--;
		tmp++;
	}
	return (ptr);
}
