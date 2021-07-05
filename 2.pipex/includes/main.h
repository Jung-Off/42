/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:38:36 by jji               #+#    #+#             */
/*   Updated: 2021/07/01 12:44:10 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

# define ERROR 1
# define SUCCESS 0
# define READ 0
# define WRITE 1

typedef struct	s_exe
{
	char			*path[5];
	char * const	*argv;
	char * const	*envp;
}				t_exe;

int				make_outfile(char *outfile);
void			*free_mem(char *const *mem);
void			init_exe(t_exe *exe, char const *argv);
void			connect_file_to_stdout(int fd);
void			connect_stdin_pipe_r(int pipefd[2]);
void			use_pipe_r_to_file(char *argv, char *file);
void			connect_file_to_stdin(const char *infile);
void			connect_stdout_pipe_w(int pipefd[2]);
void			use_pipe_w_to_stdout(char *argv);

#endif
