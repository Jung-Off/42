
CC	:= clang++
CFLAGS := -Wall -Werror -Wextra
CDEBUG = -fsanitize=address -g -std=c++98
RM := rm -f

NAME := phonebook

SRC_DIR		=	./
SRC_LIST	=	Phonebook.cpp \
				Member.cpp \
				main.cpp

HEADER		=	./

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