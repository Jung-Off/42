/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:53:41 by jji               #+#    #+#             */
/*   Updated: 2021/06/29 12:53:44 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int connect_file_to_stdout(char *outfile)
{
	int fd;

	fd = open(outfile, O_RDWR | O_CREAT, 0644);
	if( fd < 0)
	{
		perror(outfile);
		return(ERROR);
	}
	dup2(fd ,STDOUT_FILENO);
	close(fd);
	return (SUCCESS);
}

void connect_stdin_pipe_r(int pipefd[2])
{
	dup2(pipefd[READ], STDIN_FILENO);
	close(pipefd[READ]);
	close(pipefd[WRITE]);
}

void use_pipe_r_to_file(char *argv)
{
	t_exe exe;
	int i;

	i = 0;
	init_exe(&exe, argv);
	while(i++ < 5)
		execve(exe.path[i], exe.argv, exe.envp);
	perror(argv);
}