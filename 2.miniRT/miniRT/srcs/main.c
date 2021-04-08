/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:43:22 by jji               #+#    #+#             */
/*   Updated: 2021/03/29 18:42:30 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int main()
{
	int fd;
	char *line;
	t_shape shape;


	fd = open("text.rt", O_RDONLY);
	while((parse_line(fd, &line)) > 0)
	{
		printf("%s", line);

		make_struct(&line, &shape);
		free(line);
	}

	return (0);
}
