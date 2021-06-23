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

int main(int argc, char const *argv[])
{
    ft_stdin(argv[1]);
    execve ("/bin/cat", 0, 0);
    ft_stdout(argv[2]);
    
    return (SUCCESS);
}