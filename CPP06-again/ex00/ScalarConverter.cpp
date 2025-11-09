#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << BLUE << "[Default Constructor] ScalarConverter created." << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
	std::cout << "[Copy Constructor] Copied ScalarConverter." << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this != &other)
	{
		std::cout << "[Assignment Constructor] Assigning ScalarConverter." << std::endl;
	}
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << MAGENTA << "[Destructor] ScalarConverter destroyed." << RESET << std::endl;
}

static bool isPseudoLiteral(std::string const& input, std::string& type)
{
	if (input == "nanf" || input == "+inff" || input == "-inff")
	{
		type = "float";
		return true;
	}
	else if (input == "nan" || input == "+inf" || input == "-inf")
	{
		type = "double";
		return true;
	}
	return false;
}

static bool isCharLiteral(std::string const& input, std::string& type)
{
	if (input.length() == 1 && !isdigit(input[0]))
	{
		type = "char";
		return true;
	}
	return false;
}

static bool isFloatOrDoubleLiteral(std::string const& input, std::string& type)
{
	int len = input.length();

	if (len < 2)
		return false;

	bool hasDot = false;
	bool hasDigit = false;
	int i = 0;

	if (input[0] == '+' || input[0] == '-')
		i++;

	while (i < len)
	{
		if (isdigit(input[i]))
		{
			i++;
			hasDigit = true;
			continue;
		}
		if (input[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
			i++;
		}
		else if (input[i] == 'f' && i == len -1 && hasDigit && hasDot)
		{
			type = "float";
			return true;
		}
		else
			return false;
	}
	if (hasDot && hasDigit)
	{
		type = "double";
		return true;
	}

	return false;
}

static bool isIntLiteral(std::string const& input, std::string& type)
{
	int len = input.length();

	if (len < 1)
		return false;

	int i = 0;

	if ((input[0] == '+' || input[0] == '-') && len > 1)
		i++;

	while (i < len)
	{
		if (!isdigit(input[i]))
			return false;
		i++;
	}
	type = "int";
	return true;
}

static void printChar(double value)
{
	double inf = std::numeric_limits<double>::infinity();
	if (value != value || value == inf || value == -inf || value < CHAR_MIN || value > CHAR_MAX)
	{
		std::cout << "char: impossible" << std::endl;
	}
	else if (isprint(static_cast<char>(value)))
	{
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}
	else
	{
		std::cout << "char: Non displayable" << std::endl;
	}
}

static void printInt(double value)
{
	double inf = std::numeric_limits<double>::infinity();
	if (value != value || value == inf || value == -inf || value < INT_MIN || value > INT_MAX)
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

static void printFloat(double value)
{
	if (value == std::numeric_limits<double>::infinity())
		std::cout << "float: +inff" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(value) << "f" << std::endl;
}

static void printDouble(double value)
{
	if (value == std::numeric_limits<double>::infinity())
		std::cout << "double: +inf" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "double: " << value << std::endl;
}

void ScalarConverter::convert(std::string const& input)
{
	std::string type;
	double value = 0.0;

	if (isCharLiteral(input, type))
		value = static_cast<double>(input[0]);
	else if (isPseudoLiteral(input, type)
		|| (isFloatOrDoubleLiteral(input, type))
		|| (isIntLiteral(input, type)))
		value = std::strtod(input.c_str(), NULL);
	else
	{
		std::cerr << RED << "Error: Invalid literal and Unknown type." << RESET << std::endl;
		return;
	}
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

