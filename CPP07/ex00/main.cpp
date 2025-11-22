#include "whatever.hpp"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define RESET		"\033[0m"

int main( void )
{
	int a = 2;
	int b = 3;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;

	::swap( a, b );
	std::cout << YELLOW << "After swap: a = " << a << ", b = " << b << std::endl;
	std::cout << BLUE << "min( a, b ) = " << ::min( a, b ) << RESET << std::endl;
	std::cout << MAGENTA << "max( a, b ) = " << ::max( a, b ) << RESET << std::endl;
	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << YELLOW << "After swap: c = " << c << ", d = " << d << std::endl;
	std::cout << BLUE << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << MAGENTA << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}
