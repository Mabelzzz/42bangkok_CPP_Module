NAME = bureaucrat

SRC = main.cpp Bureaucrat.cpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

HPP_FILE = Bureaucrat.hpp

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp $(HPP_FILE)
		$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
