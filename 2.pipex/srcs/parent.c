/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:53:32 by jji               #+#    #+#             */
/*   Updated: 2021/06/30 15:08:11 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int		make_outfile(char *outfile)
{
	int fd;

	fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(outfile);
		exit(ERROR);
	}
	return (fd);
}

void	connect_file_to_stdout(int fd)
{
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	connect_stdin_pipe_r(int pipefd[2])
{
	dup2(pipefd[READ], STDIN_FILENO);
	close(pipefd[READ]);
	close(pipefd[WRITE]);
}

void	use_pipe_r_to_file(char *argv, char *file)
{
	t_exe	exe;
	int		i;

	i = 0;
	init_exe(&exe, argv);
	while (i < 5)
		execve(exe.path[i++], exe.argv, exe.envp);
	free_mem(exe.argv);
	unlink(file);
	perror(argv);
	exit(ERROR);
}
