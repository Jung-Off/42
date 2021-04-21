/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 00:26:01 by jji               #+#    #+#             */
/*   Updated: 2020/12/27 23:46:17 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s;

	i = 0;
	if (!(s = (char*)malloc(ft_strlen(s1) * sizeof(char) + 1)))
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		++i;
	}
	s[i] = '\0';
	return (s);
}
