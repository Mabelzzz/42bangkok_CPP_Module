NAME = megaphone

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

CC = g++

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $@
	@say -v Kanya "คอมพายเมก้าโฟนโอนโอน"

clean:
	@rm -f $(OBJ)
	# @say -v Samantha "clean clean clean"

fclean: clean
	@rm -f $(NAME)
	# @say -v Samantha "f clean bye"

re: fclean all

.PHONY: all clean fclean re
