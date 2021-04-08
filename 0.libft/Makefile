# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/23 22:14:46 by jji               #+#    #+#              #
#    Updated: 2021/02/07 10:34:58 by jji              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_memset\
		ft_memcpy\
		ft_memccpy\
		ft_memchr\
		ft_strlen\
		ft_strchr\
		ft_strnstr\
		ft_calloc\
		ft_strncmp\
		ft_memcmp\
		ft_substr\
		ft_strdup\
		ft_strjoin\
		ft_strlcpy\
		ft_strlcat\
		ft_strtrim\
		ft_split


FILES_B = ft_lstnew \
		  ft_lstadd_front \
		  ft_lstsize \
		  ft_lstlast \
			ft_lstadd_back \
			ft_lstdelone \
			ft_lstclear \
			ft_lstiter \
			ft_lstmap

SRCS_DIR =./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_B)))

OBJS_DIR =./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	$(AR) $@ $^

bonus : $(OBJS_B)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME)

re: clean all

.PHONY : bonus all clean fclean re
