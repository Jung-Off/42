/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:09:14 by jji               #+#    #+#             */
/*   Updated: 2020/12/29 23:43:49 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(const char *s1, const char *set)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		++i;
	}
	return (i);
}

static int	ft_end(const char *s1, const char *set)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(s1);
	while (0 < len)
	{
		if (ft_strchr(set, s1[len - 1]) == 0)
			break ;
		--len;
	}
	return (len);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new_s;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	if (!(new_s = (char*)malloc(end - start + 1)))
		return (0);
	ft_strlcpy(new_s, s1 + start, end - start + 1);
	return (new_s);
}
