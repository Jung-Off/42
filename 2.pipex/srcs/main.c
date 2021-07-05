/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:37:01 by jji               #+#    #+#             */
/*   Updated: 2021/07/01 12:49:27 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	*free_mem(char *const *mem)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (mem[n] != NULL)
		n++;
	while (i < n)
		free((void *)mem[i++]);
	free((void *)mem);
	return (0);
}

void	init_exe(t_exe *exe, char const *argv)
{
	char **cmd;

	cmd = ft_split(argv, ' ');
	if (cmd == NULL)
		exit(1);
	exe->path[0] = ft_strjoin("/usr/local/bin/", cmd[0]);
	exe->path[1] = ft_strjoin("/usr/bin/", cmd[0]);
	exe->path[2] = ft_strjoin("/bin/", cmd[0]);
	exe->path[3] = ft_strjoin("/usr/sbin/", cmd[0]);
	exe->path[4] = ft_strjoin("/sbin/", cmd[0]);
	exe->argv = (char *const *)cmd;
	exe->envp = NULL;
}

void	error_argc(int argc)
{
	if (argc != 5)
		exit(1);
}

int		main(int argc, char *argv[])
{
	int		pipefd[2];
	pid_t	pid;
	int		status;
	int		fd;

	error_argc(argc);
	pipe(pipefd);
	fd = make_outfile(argv[4]);
	pid = fork();
	if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WEXITSTATUS(status) == 1)
			exit(1);
		connect_file_to_stdout(fd);
		connect_stdin_pipe_r(pipefd);
		use_pipe_r_to_file(argv[3], argv[4]);
	}
	else if (pid == 0)
	{
		connect_file_to_stdin(argv[1]);
		connect_stdout_pipe_w(pipefd);
		use_pipe_w_to_stdout(argv[2]);
	}
	return (0);
}
