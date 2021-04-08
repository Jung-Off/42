/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:09:36 by jji               #+#    #+#             */
/*   Updated: 2021/04/06 21:00:49 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_space(char *dup)
{
	int i = 0;
	while (dup[i])
	{
		if (dup[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*dup;
	int		i = 0;

	if (!(dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	while (s1[i])
	{
		dup[i] = s1[i];
		++i;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sum;
	int		i = 0;

	if (!s1)
		return (ft_strdup(s2));
	if (!(sum = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (s1[i])
	{
		sum[i] = s1[i];
		i++;
	}
	while (*s2)
		sum[i++] = *s2++;
	sum[i] = 0;
	free(s1);
	return (sum);
}

int	input_line(char **line, char **dup, int newline_i)
{
	(*dup)[newline_i] = '\0';
	*line = ft_strdup(*dup);
	free(*dup);
	*dup = 0;
	return (1);
}

int	last_input(char **line, char **dup, int rd_size)
{
	if (rd_size < 0)
		return (-1);
	if (*dup)
	{
		*line = *dup;
		*dup = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(char **line)
{
	static char	*dup;
	char		buf[2];
	int			rd_size;
	int			newline_i;

	while ((rd_size = read(0, buf, 1)) > 0)
	{
		buf[rd_size] = '\0';
		dup = ft_strjoin(dup, buf);
		if ((newline_i = ft_space(dup)) >= 0)
			return (input_line(line, &dup, newline_i));
	}
	return (last_input(line, &dup, rd_size));
}
