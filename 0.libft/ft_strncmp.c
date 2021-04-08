/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:42:41 by jji               #+#    #+#             */
/*   Updated: 2021/01/04 21:17:55 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *new_s1;
	unsigned char *new_s2;

	new_s1 = (unsigned char*)s1;
	new_s2 = (unsigned char*)s2;

	size_t i;	
	i = 0;
	if(n == 0)
		return (0);
	while(new_s1[i] == new_s2[i] && new_s1[i] != '\0' && new_s2[i] != '\0' && i < n - 1)
		++i;
	return(new_s1[i] - new_s2[i]);
}
