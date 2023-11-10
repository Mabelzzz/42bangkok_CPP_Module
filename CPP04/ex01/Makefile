NAME = Polymorphism

SRC =	main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \

OBJ = $(SRC:.cpp=.o)

CXX = c++

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
