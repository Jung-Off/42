
CC	:= clang++
CFLAGS := -Wall -Werror -Wextra
RM := rm -f

NAME := phonebook

SRC_DIR		=	./
SRC_LIST	=	phonebook.cpp
HEADER		=	phonebook.hpp
SRC			=	$(addprefix $(SRC_DIR), $(SRC_LIST))
OBJ			=	$(SRC:.cpp=.o)

%.o			:	%.cpp
				@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

$(NAME)		:	$(OBJ)
				@$(CC) $(CFALGS) -I $(HEADER) -o $(NAME) $(OBJ)

.PHONY		:	all clean fclean re

all			:	$(NAME)

clean		:
				@$(RM) $(OBJ)

fclean		:	clean
				@$(RM) $(NAME)

re			:	fclean all