#ifndef BASE_HPP
#define BASE_HPP

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
// # define RED		"\033[31m"
# define GRAY		"\033[0;90m"
# define RESET		"\033[0m"

#include <iostream>


class Base
{
	public:
		virtual ~Base();

};

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif
