NAME = Harl

SRC =	main.cpp \
		Harl.cpp \

OBJ = $(SRC:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
