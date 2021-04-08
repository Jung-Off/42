/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 22:24:37 by jji               #+#    #+#             */
/*   Updated: 2021/01/04 22:44:05 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char *sum;
	int i;
	int j;

	j = 0;
	i = 0;
	if(s1 == 0 || s2 == 0)
		return (0);
	if(!(sum = (char*)malloc(ft_strlen(s1) +ft_strlen(s2) + 1)))
		return (0);

	while(s1[i])
	{
		sum[i] = s1[i];
		++i;
	}
	while(s2[j])
	{
		sum[i + j] = s2[j];
		++j;
	}
	sum[i + j] = '\0';
	return(sum);
}

