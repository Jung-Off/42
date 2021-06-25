/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:37:01 by jji               #+#    #+#             */
/*   Updated: 2021/06/22 20:37:02 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int ft_stdin(char *input)
{
    int fd;

    fd = open(input, O_RDONLY);
    if (fd < 0)
    {
        perror(input);
        return (ERROR);
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
    return (SUCCESS);
}

int ft_stdout(char *output)
{
    int fd;

    fd = open(output, O_RDWR | O_CREAT, 0644);
    if (fd < 0)
    {
        perror(output);
    	return (ERROR);
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    return (SUCCESS);
}

void ft_close(int pipefd[2])
{
    close(pipefd[READ]);
    close(pipefd[WRITE]);
}

void exe_init(t_exe *exe, char *argv)
{
    char **dump;

    dump = ft_split(argv, ' ');
    exe->cmd[0] = ft_strjoin("/usr/local/bin/", dump[0]);
    exe->cmd[1] = ft_strjoin("/usr/bin/", dump[0]);
    exe->cmd[2] = ft_strjoin("/bin/", dump[0]);
    exe->cmd[3] = ft_strjoin("/usr/sbin/", dump[0]);
    exe->cmd[4] = ft_strjoin("/sbin/", dump[0]);
    exe->argv = dump;
	exe->envp = NULL;
}

void ft_exe(char *argv)
{
    t_exe	exe;
    int		i;

    i = 0;
    exe_init(&exe, argv);
    while(i++ < 5)
        execve(exe.cmd[i], exe.argv, exe.envp);
    perror(exe.argv[0]);
}

int main(int argc, char *argv[])
{
    int pipefd[2];
    pid_t pid;

    pipe(pipefd);
    pid = fork();
    if (pid > 0)
    {
        ft_stdin(argv[1]);
        dup2(pipefd[WRITE], STDOUT_FILENO);
        ft_close(pipefd);
        ft_exe(argv[2]);
    }
    else if (pid == 0)
    {
        ft_stdout(argv[4]);
        dup2(pipefd[READ], STDIN_FILENO);
        ft_close(pipefd);
        ft_exe(argv[3]);
    }
    return (0);
}