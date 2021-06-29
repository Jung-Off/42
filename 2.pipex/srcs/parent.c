/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:53:32 by jji               #+#    #+#             */
/*   Updated: 2021/06/29 12:53:34 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int connect_file_to_stdin(const char *infile)
{
	int fd;

	fd = open(infile, O_RDONLY);
	if(fd < 0)
	{
		perror(infile);
		return (ERROR);
	}
	dup2(fd ,STDIN_FILENO);
	close(fd);
	return (SUCCESS);
}

void connect_stdout_pipe_w(int pipefd[2])
{
	dup2(pipefd[WRITE], STDOUT_FILENO);
	close(pipefd[READ]);
	close(pipefd[WRITE]);
}

void use_pipe_w_to_stdout(char *argv)
{
	t_exe exe;
	int i;

	i = 0;
	init_exe(&exe, argv);
	while(i++ < 5)
		execve(exe.path[i], exe.argv, exe.envp);
	perror(argv);
}