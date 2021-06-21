#**************************************************************************** #
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

CC := gcc
CFLAGS := -Wall -Wextra -Werror

SRC_DIR := ./srcs/
SRC_NAME := a_to_b.c \
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
SRCS := $(addprefix $(SRC_DIR), $(SRC_NAME)) 

OBJ_DIR := ./objs/
OBJ_NAME := $(SRC_NAME:.c=.o)
OBJ := $(addprefix $(OBJ_DIR), $(OBJ_NAME))

INCLUDE := -I./includes

.PHONY : all clean fclean re norm

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^
	@echo "\x1b[32m\nStart program\x1b[0m"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all : $(NAME)

clean :
		@rm -r $(OBJ_DIR)
		@echo "\x1b[31mCLEAN\x1b[0m"
fclean : clean
		@rm -f $(NAME)
		@echo "\x1b[31;101mFCLEAN\x1b[0m"

re : fclean all

norm :
		@norminette .
