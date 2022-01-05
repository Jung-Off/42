
CC	:= clang++
CFLAGS := -Wall -Werror -Wextra
RM := rm -f

NAME := megaphone

SRC_DIR		=	./
SRC_LIST	=	megaphone.cpp
SRC			=	$(addprefix $(SRC_DIR), $(SRC_LIST))
OBJ			=	$(SRC:.cpp=.o)

%.o			:	%.cpp
				@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME)		:	$(OBJ)
				@$(CC) $(CFALGS) -o $(NAME) $(OBJ)

.PHONY		:	all clean fclean re

all			:	$(NAME)

clean		:
				@$(RM) $(OBJ)

fclean		:	clean
				@$(RM) $(NAME)

re			:	fclean all