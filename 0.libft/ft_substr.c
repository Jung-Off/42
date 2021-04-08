/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 21:41:59 by jji               #+#    #+#             */
/*   Updated: 2021/01/04 21:59:02 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *temp;
	size_t i;

	i = 0;

	if(s == 0)
		return(0);
	if(ft_strlen(s) <start)
		return(ft_strdup(""));

	if(!(temp = (char*)malloc(sizeof(char) * len + 1)))
			return(0);
	while(i < len && s[start + i])
	{
		temp[i] = s[start + i];
		++i;
	}
	temp[i] ='\0';

	return(temp);
	}

