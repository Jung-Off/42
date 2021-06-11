# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 11:08:18 by jji               #+#    #+#              #
#    Updated: 2021/06/11 11:46:20 by jji              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
SRC_DIR := ./srcs/
SRC = a_to_b.c \
	   b_to_a.c \
	   checker.c \
	   cmd_push.c \
	   cmd_rotate.c \
	   cmd_rrotate.c \
	   cmd_swap.c \
	   error.c \
	   just_3.c \
	   main.c \
	   make_list.c \
	   save_num.c \
	   setup_pivot.c \
	   utils.c

SRCS = $(addprefix $(SRC_DIR), $(SRC)) 

OBJS := $(SRCS:.c=.o)
CC := gcc
CFLAGS := -Wall -Wextra -Werror
INCLUDE := -I./includes

.PHONY : all clean fclean re

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all : $(NAME)

clean :
		rm -f $(OBJS)
fclean : clean
		rm -f $(NAME)
re : fclean all
