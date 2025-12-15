#include "RPN.hpp"

int main(int argc, char* argv[])
{
	try
	{
		if (argc != 2)
		{
			std::cerr << RED "Error: Invalid number of arguments. Usage: ./rpn \"<expression>\"" RESET << std::endl;
			return 1;
		}
		RPN rpnCalculator;
		rpnCalculator.calculate(argv[1]);
	}
	catch (const std::exception& e)
	{
		return 1;
	}

	return 0;
}
