# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 16:15:16 by jji               #+#    #+#              #
#    Updated: 2021/05/18 17:17:25 by jji              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET		= miniRT

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f

LIBFT_DIR	= ./libft/
MLX_DIR		= ./mlx/
INCS_DIR	= ./includes/
SRCS_DIR	= ./srcs/

SRC			= convert.c \
			  draw.c \
			  error.c \
			  get_next_line.c \
			  hit.c \
			  hit_cylinder.c \
			  hit_cylinder2.c \
			  hit_figures.c \
			  hit_plane.c \
			  hit_sphere.c \
			  hit_square.c \
			  hit_triangle.c \
			  main.c \
			  parse.c \
			  parse_figures.c \
			  phong_lighting.c \
			  ray.c \
			  save_image.c \
			  utils.c \
			  vec_mul.c \
			  vec_operation.c \
			  vec_utils.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRC))
OBJS		= $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(TARGET) : $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -I $(INCS_DIR) -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

all : $(TARGET)

clean : 
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(TARGET)

re : clean all

.PHONY : all clean fclean re
