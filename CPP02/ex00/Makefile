NAME = Fixed

SRC =	main.cpp \
		Fixed.cpp \

OBJ = $(SRC:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $@
	# @say -v Kanya "คอมพายเมก้าโฟนโอนโอน"

clean:
	@rm -f $(OBJ)
	# @say -v Samantha "already clean"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
