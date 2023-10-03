#include <iostream>

# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define GREEN		"\033[0;32m"

int main(void) {
  std::string string = "HI THIS IS BRAIN";
  std::string* stringPTR = &string;
  std::string& stringREF = string;

  std::cout << GREEN << "Memory address:" << std::endl;

  std::cout << BLUE << "string:    " << &string << std::endl;
  std::cout << BLUE << "stringPTR: " << stringPTR << std::endl;
  std::cout << BLUE << "stringREF: " << &stringREF << std::endl;

  std::cout << GREEN << "Value pointed:" << std::endl;

  std::cout << MAGENTA << "string:    " << string << std::endl;
  std::cout << MAGENTA << "stringPTR: " << *stringPTR << std::endl;
  std::cout << MAGENTA << "stringREF: " << stringREF << std::endl;
}
