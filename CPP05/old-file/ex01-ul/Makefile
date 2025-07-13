NAME = bureaucrat

SRC = main.cpp Bureaucrat.cpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

HPP_FILE = Bureaucrat.hpp

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp $(HPP_FILE)
		$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
		$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean :
		rm $(OBJ)

fclean : clean
		rm $(NAME)

re : fclean all

.PHONY : all clean fclean re
