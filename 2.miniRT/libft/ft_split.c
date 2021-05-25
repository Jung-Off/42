/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:07:17 by jji               #+#    #+#             */
/*   Updated: 2020/12/29 23:43:16 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_count(const char *str, char c)
{
	size_t i;
	size_t num;

	i = 0;
	num = 0;
	while (str[i] != 0)
	{
		if (str[i] != c && str[i] != 0)
		{
			num++;
			while (str[i] != c && str[i] != 0)
				i++;
		}
		else if (str[i] != 0)
			i++;
	}
	return (num);
}

static void		f_strcpy(char *dst, char const *src, int st, int la)
{
	int i;

	i = 0;
	while (st < la)
	{
		dst[i] = src[st];
		i++;
		st++;
	}
	dst[i] = 0;
}

static void		*f_mem(char **mem, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		free(mem[i]);
		i++;
	}
	free(mem);
	return (0);
}

static void		split(char const *s, char c, char **str)
{
	size_t i;
	size_t j;
	size_t pin;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && s[i] != 0)
		{
			pin = i;
			while (s[i] != c && s[i] != 0)
				i++;
			if (((str[j] = (char*)malloc(sizeof(char) * (i - pin + 1)))) == 0)
			{
				f_mem(str, j);
				return ;
			}
			f_strcpy(str[j], s, pin, i);
			j++;
		}
		else if (s[i] != 0)
			i++;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	size_t	n;

	if (s == 0)
		return (0);
	n = str_count(s, c);
	str = (char **)malloc(sizeof(char *) * (n + 1));
	if (str == 0)
		return (0);
	str[n] = 0;
	if (n == 0)
		return (str);
	split(s, c, str);
	return (str);
}
