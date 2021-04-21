# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 15:37:01 by jji               #+#    #+#              #
#    Updated: 2021/03/29 16:27:12 by jji              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c \
	srcs/parse_line.c

LIBFT = libft

LIBFT_A = libft.a

INCLUDES = ./includes

OBJS = $(SRCS:.c=.o)

NAME = libminiRT.a

ARRC = ar rc

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I$(INCLUDES)

$(NAME):	$(OBJS)
		make all -C $(LIBFT)/
		cp $(LIBFT)/$(LIBFT_A) $(NAME)
		$(ARRC) $(NAME) $(OBJS)



all :		$(NAME)

clean :
			$(RM) -f $(OBJS)
			make clean -C $(LIBFT)

fclean :	clean
			$(RM) $(NAME)
			make fclean -C $(LIBFT)

re :		fclean all

.PHONY : all clean fclean re
