# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 20:36:44 by jji               #+#    #+#              #
#    Updated: 2021/06/22 20:36:46 by jji              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := pipex


CC := gcc
CFLAGS := -Wall -Wextra -Werror

SRC_DIR := ./srcs/
SRC_NAME := child.c \
	   parent.c \
	   main.c
	   
SRCS := $(addprefix $(SRC_DIR), $(SRC_NAME)) 

OBJ_DIR := ./objs/
OBJ_NAME := $(SRC_NAME:.c=.o)
OBJ := $(addprefix $(OBJ_DIR), $(OBJ_NAME))

INCLUDE := -I. -I./libft

LIB_DIR = ./libft/
LIB_NAME = ft
LIB = $(LIB_DIR)lib$(LIB_NAME).a

.PHONY : all clean fclean re norm

$(NAME) : $(LIB) $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDE) -L$(LIB_DIR) -l$(LIB_NAME) -o $@ $^
	@echo "\x1b[32m\nStart PIPEX\x1b[0m"

$(LIB) :
	@make -C $(LIB_DIR) all

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


all : $(NAME)

clean :
		@rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean
		@echo "\x1b[31mCLEAN_PIPEX\x1b[0m"
fclean : clean
		@rm -f $(NAME)
		@make -C $(LIB_DIR) fclean
		@echo "\x1b[31;101mFCLEAN_PIPEX\x1b[0m"

re : fclean all

norm :
		@norminette .