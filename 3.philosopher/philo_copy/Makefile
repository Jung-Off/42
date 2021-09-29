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
CFLAGS := -Wall -Wextra -Werror #-g3 -fsanitize=address

SRCS := main.c \
		init.c \
		utils.c \
		print.c \
		time.c \
		act.c \
		check.c

OBJS := $(SRCS:.c=.o)

INCLUDE := -I.
.PHONY:		all clean fclean re norm test0 test1 test2 test3 test4 test5 test6

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

test0:		re
			@./$(NAME) 4 410 200 200
			# "no one should die"

test1:		re
			@./$(NAME) 5 800 200 200
			# "no one should die"

test2:		re
			@./$(NAME) 5 800 200 200
			# "no one should die"

test3:		re
			@./$(NAME) 5 800 200 200 7
			# "no one should die"

test4:		re
			@./$(NAME) 4 310 200 100
			# "a philosopher should die"

test5:		re
			@./$(NAME) 1 800 200 200
			# "a philosopher should die"

test6:	re
			@./$(NAME) 3 4100 2000 2000
			# "check if philo die right time"


norm :
		@norminette .