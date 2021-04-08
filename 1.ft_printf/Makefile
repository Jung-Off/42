# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 20:25:55 by jji               #+#    #+#              #
#    Updated: 2021/02/16 14:06:53 by jji              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c\
		ft_format.c\
		ft_flagsetup.c\
		ft_libft_fix.c\
		ft_formu.c\
		ft_forms.c

LIBFT = libft

LIBFT_A = libft.a

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

ARRC = ar rc

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
		make all -C $(LIBFT)/
		cp $(LIBFT)/$(LIBFT_A) $(NAME)
		$(ARRC) $(NAME) $(OBJS)

all :		$(NAME)

clean :
			$(RM) -f $(OBJS) $(OBJS_B)
			make clean -C $(LIBFT)

fclean :	clean
			$(RM) $(NAME) $(bonus)
			make fclean -C $(LIBFT)

re :		fclean all

.PHONY : all clean fclean re .c.o
