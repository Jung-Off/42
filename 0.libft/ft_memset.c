/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 22:30:13 by jji               #+#    #+#             */
/*   Updated: 2020/12/31 23:45:13 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*new_b;
	unsigned char	new_c;
	size_t			i;

	i = 0;
	new_c = c;
	new_b = b;
	while (i < len)
	{
		new_b[i] = new_c;
		++i;
	}
	return (b);
}

