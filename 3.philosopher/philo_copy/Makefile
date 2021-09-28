# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 14:43:47 by jji               #+#    #+#              #
#    Updated: 2021/09/16 14:43:48 by jji              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

CC := gcc
CFLAGS := -Wall -Wextra -Werror -g3 -fsanitize=address

SRCS := main.c \
		init.c \
		utils.c \

OBJS := $(SRCS:.c=.o)

INCLUDE := -I.
.PHONY : all clean fclean re norm

$(NAME) : $(OBJS)
		@$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^
		@printf " \x1b[32m\nStart program\x1b[0m \n"
%.o : %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "Generating philosopher's table... %-33.33s\r" $@

all : $(NAME)

clean :
		@rm -rf $(OBJS)
		@printf "\x1b[31mCLEAN\x1b[0m\n"
fclean : clean
		@rm -rf $(NAME)
		@printf "\x1b[31;101mFCLEAN\x1b[0m\n"
		
re : fclean all

norm :
		@norminette .