
CC	:= clang++
CFLAGS := -Wall -Werror -Wextra
RM := rm -f


NAME := megaphone
HEADER		=	./
SRC_DIR := ./
SRC_LIST	=	megaphone.cpp
SRC			=	$(addprefix $(SRC_DIR), $(SRC_LIST))
OBJ			=	$(SRC:.cpp=.o)

%.o			:	%.cpp
				@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

$(NAME)		:	$(OBJ)
				@$(CC) $(CFALGS) -I $(HEADER) -o $(NAME) $(OBJ)

.PHONY		:	all clean fclean re

all			:	$(NAME)

clean		:
				@echo "Cleaning object files..." 
				@$(RM) $(OBJ)
				@echo "Object files are cleaned!\n"

fclean		:	clean
				@echo "Removing $(NAME)..."
				@$(RM) $(NAME)
				@echo "$(NAME) is removed!"

re			:	fclean all