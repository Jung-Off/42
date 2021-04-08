/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:31:09 by jji               #+#    #+#             */
/*   Updated: 2021/01/05 21:40:02 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int ft_postion(char s1, char const *set)
{
	int i;
	
	i = 0;
	while(set[i])
	{
		if(s1 == set[i])
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char *new;
	int i;
	int start;
	int end;

	i = 0;
	start = 0;
	if(s1 == 0)
		return(0);
	end = ft_strlen(s1) - 1;
	while(s1[start] &&  ft_postion(s1[start], set))
		++start;
	while(start < end && ft_postion(s1[end], set))
		--end;
	if(!(new = (char*)malloc(sizeof(char) * (end - start + 2))))
		return (0);
	while(start <= end)
	{
		new[i] = s1[start];
		++i;
		++start;
	}
	new[i] ='\0';
	return(new);
}

