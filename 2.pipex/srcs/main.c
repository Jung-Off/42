/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:37:01 by jji               #+#    #+#             */
/*   Updated: 2021/06/30 15:07:30 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	init_exe(t_exe *exe, char const *argv)
{
	char **cmd;

	cmd = ft_split(argv, ' ');
	exe->path[0] = ft_strjoin("/usr/local/bin/", cmd[0]);
	exe->path[1] = ft_strjoin("/usr/bin/", cmd[0]);
	exe->path[2] = ft_strjoin("/bin/", cmd[0]);
	exe->path[3] = ft_strjoin("/usr/sbin/", cmd[0]);
	exe->path[4] = ft_strjoin("/sbin/", cmd[0]);
	exe->argv = (char *const *)cmd;
	exe->envp = NULL;
}

int		main(int argc, char *argv[])
{
	int		pipefd[2];
	pid_t	pid;
	int		status;

	if(argc != 5)
		return (1);
	pipe(pipefd);
	pid = fork();
	if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if(WIFEXITED(status) == 0)
			exit(1);
		connect_file_to_stdout(argv[4]);
		connect_stdin_pipe_r(pipefd);
		use_pipe_r_to_file(argv[3]);
	}
	else if (pid == 0)
	{
		connect_file_to_stdin(argv[1]);
		connect_stdout_pipe_w(pipefd);
		use_pipe_w_to_stdout(argv[2]);
	}
	return (0);
}
