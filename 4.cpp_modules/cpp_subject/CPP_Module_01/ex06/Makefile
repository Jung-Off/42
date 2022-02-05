
NAME := KarenFilter

CC := clang++
CFLAGS := -Wall -Wextra -Werror
CDEBUG = -fsanitize=address -g -std=c++98

SRCS := main.cpp \
		Karen.cpp

OBJ_DIR := ./objs/
OBJ_NAME := $(SRCS:.cpp=.o)
OBJ := $(addprefix $(OBJ_DIR), $(OBJ_NAME))

.PHONY : all clean fclean re

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(CDEBUG) -o $@ $^
	@echo "\x1b[32m\nStart $(NAME)\x1b[0m"

$(OBJ_DIR)%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
		@rm -rf $(OBJ_DIR)
		@rm -rf file.replace
		@echo "\x1b[31mCLEAN_$(NAME)\x1b[0m"

fclean : clean
		@rm -f $(NAME)
		@echo "\x1b[31;101mFCLEAN_$(NAME)\x1b[0m"

re : fclean all