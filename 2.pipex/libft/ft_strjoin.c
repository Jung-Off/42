/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 01:33:01 by jji               #+#    #+#             */
/*   Updated: 2020/12/25 13:32:40 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sum;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s1) || !(s2))
		return (NULL);
	if (!(sum = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	while (s1[i])
	{
		sum[i] = s1[i];
		++i;
	}
	while (s2[j])
	{
		sum[i + j] = s2[j];
		++j;
	}
	sum[i + j] = 0;
	return (sum);
}
