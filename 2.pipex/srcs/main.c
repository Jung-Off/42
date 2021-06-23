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

int ft_stdin(const char *input)
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

int ft_stdout(const char *output)
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

static void connect_pipe(int pipefd[2], int io)
{
    dup2(pipefd[io], io);
    close(pipefd[0]);
    close(pipefd[1]);
}

int main(int argc, char const *argv[])
{

    int pipefd[2];
    pid_t pid;

    pipe(pipefd);
    pid = fork();

    if (pid > 0)
    {
        ft_stdout(argv[argc - 1]);
        connet_pipe(pipefd, STDIN_FILENO);
    }
    else if (pid == 0)
    {
        ft_stdin(argv[1]);
        connet_pipe(pipefd, STDOUT_FILENO);
    }
    return (SUCCESS);
}