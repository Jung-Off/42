#ifndef _PARSE_LINE_H
# define _PARSE_LINE_H

# include <stdlib.h>

int ft_newline(char *dup);
int input_line(char **line, char *dup);
int last_line(char **line, char *dup, int rd_size);
char *ft_straddchar(char *s1, char *s2);
int parse_line(int fd, char **line);

#endif
