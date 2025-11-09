#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: Invalid number of arguments." << RESET << std::endl;
		return 1;
	}
	double v = .8;
	std::cout << "double: " << v << std::endl;
	std::cout << "Input literal: " << argv[1] << std::endl;
	ScalarConverter::convert(argv[1]);
	return 0;
}
