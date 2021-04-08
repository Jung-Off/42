/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:15:15 by jji               #+#    #+#             */
/*   Updated: 2021/03/29 16:59:50 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int ft_newline(char *dup)
{
	int i;

	i = 0;
	while(dup[i])
	{
		if(dup[i] == '\n')
			return(1);
		++i;
	}
	return(0);
}

int input_line(char **line, char *dup)
{
	*line = ft_strdup(dup);
	free(dup);
	dup = 0;
	return(1);
}

char *ft_straddchar(char *s1, char *s2)
{
	int s1_len;
	int s2_len;
	int i;
	char *sum;

	i = 0;
	if(!s1)
		return(ft_strdup(s2));	
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(sum = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	while(*s1)
		sum[i++] = *s1++;
	while(*s2)
		sum[i++] = *s2++;
	sum[i] = '\0';
	
	return(sum);
}

int parse_line(int fd, char **line)
{
	int 		rd_size;
	char		buf[2];
	static char *dup;

	while ((rd_size = read(fd, buf, 1)) > 0)
	{
		buf[rd_size] ='\0';
		dup = ft_straddchar(dup, buf);
		if (ft_newline(dup))
			return (input_line(line, dup));
	}
	return (0);
}
