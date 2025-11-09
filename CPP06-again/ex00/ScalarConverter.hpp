#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define GRAY		"\033[0;90m"
# define RESET		"\033[0m"

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits> // For INT_MIN, INT_MAX, CHAR_MIN, CHAR_MAX
#include <limits> // For std::numeric_limits
#include <iomanip> // For std::setprecision

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static void convert(std::string const& literal);
};


#endif
