/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:09:36 by jji               #+#    #+#             */
/*   Updated: 2021/01/26 18:01:09 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_space(char *dup)
{
	int i;

	i = 0;
	while (dup[i])
	{
		if (dup[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

int	input_line(char **line, char **dup, int newline_i)
{
	int		index;
	char	*temp;

	(*dup)[newline_i] = '\0';
	*line = ft_strdup(*dup);
	index = ft_strlen(*dup + newline_i + 1);
	if (index == 0)
	{
		free(*dup);
		*dup = 0;
		return (1);
	}
	temp = ft_strdup(*dup + newline_i + 1);
	free(*dup);
	*dup = temp;
	return (1);
}

int	last_input(char **line, char **dup, int rd_size)
{
	int newline_i;

	if (rd_size < 0)
		return (-1);
	if (*dup && (newline_i = ft_space(*dup)) >= 0)
		return (input_line(line, dup, newline_i));
	else if (*dup)
	{
		*line = *dup;
		*dup = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*dup[OPEN_MAX];
	int			rd_size;
	int			newline_i;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((rd_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd_size] = '\0';
		dup[fd] = ft_strjoin(dup[fd], buf);
		if ((newline_i = ft_space(dup[fd])) >= 0)
			return (input_line(line, &dup[fd], newline_i));
	}
	return (last_input(line, &dup[fd], rd_size));
}
