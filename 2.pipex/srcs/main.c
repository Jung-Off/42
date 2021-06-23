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

int ft_stdin(const char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        //perror(file);
        return (ERROR);
    }
    dup2(fd, STDIN_FILENO);
    close(fd);

    return (SUCCESS);
}

int main(int argc, char const *argv[])
{
    ft_stdin(argv[1]);
    execve ("/bin/cat", 0, 0);

    return (SUCCESS);
}