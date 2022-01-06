
CC	:= clang++
CFLAGS := -Wall -Werror -Wextra -std=c++98
# CDEBUG = -fsanitize=address -g -std=c++98
RM := rm -f

NAME := Zombie

SRC_DIR		=	./
SRC_LIST	=	newZombie.cpp \
				randomChump.cpp \
                Zombie.cpp \
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