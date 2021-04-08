#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int 	ft_space(char *dup);
char	*ft_straddchar(char *s1, char *s2);
int		input_line(char **line, char **dup, int newline_i);
int		last_input(char **line, char **dup, int rd_size);
int		get_next_line(int fd, char **line);

#endif
