/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 00:39:49 by jji               #+#    #+#             */
/*   Updated: 2020/12/28 22:57:08 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!(temp = (char*)malloc(len * sizeof(char) + 1)))
		return (0);
	while (len > 0 && s[start + i])
	{
		temp[i] = s[start + i];
		++i;
		--len;
	}
	temp[i] = '\0';
	return (temp);
}
