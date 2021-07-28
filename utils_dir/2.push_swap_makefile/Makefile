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
SHELL	:= bash
.PHONY : all clean fclean re norm

$(NAME) : $(OBJ)
	@./wave.sh
	@./spinner.sh
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^
	@printf "\b\b\b\b\b\b\b\b\b\b\b \x1b[32m\nStart program\x1b[0m \n"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@printf "Generating... %-33.33s\r" $@
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all : $(NAME)

clean :
		@rm -rf $(OBJ_DIR)
		@printf "\x1b[31mCLEAN\x1b[0m\n"
fclean : clean
		@rm -f $(NAME)
		@printf "\x1b[31;101mFCLEAN\x1b[0m\n"

re : fclean all

norm :
		@norminette .
