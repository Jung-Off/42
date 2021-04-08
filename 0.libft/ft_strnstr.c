/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:31:21 by jji               #+#    #+#             */
/*   Updated: 2021/01/04 19:41:37 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if(*small == 0)
		return ((char*)big);
	while(big[i] && i < len)
	{
		j = 0;
		if(big[i] == small[j])
		{
			while(small[j])
			{
				if(big[i + j] != small[j] || i + j >=	len)
					break;
				++j;
			}
			if(small[j]== 0)
				return((char*)big + i);
		}
			++i;
	}
	return (0);
}

