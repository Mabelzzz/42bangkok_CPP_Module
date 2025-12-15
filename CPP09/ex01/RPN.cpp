#include "RPN.hpp"

RPN::RPN() {}
// {
// 	std::cout << BLUE << "[Default Constructor] RPN created." << RESET << std::endl;
// }

RPN::RPN(const RPN& copy)
{
	*this = copy;
	// std::cout << "[Copy Constructor] Copied RPN." << std::endl;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		// std::cout << "[Assignment Constructor] Assigning RPN." << std::endl;
		this->_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {}
// {
// 	std::cout << MAGENTA << "[Destructor] RPN destroyed." << RESET << std::endl;
// }

void RPN::calculate(const std::string& expression)
{
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token)
	{
		if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
		{
			if (_stack.size() < 2)
			{
				std::cerr << RED << "Error: Not enough operands for operation " << token << RESET << std::endl;
				throw RPNException();
			}
			operation(token[0]);
		}
		else if (isAllDigits(token))
		{
			int number = std::stoi(token);
			if (number < 0 || number > 9)
			{
				std::cerr << RED << "Error: Number out of range (0-9) => " << number << RESET << std::endl;
				throw RPNException();
			}
			_stack.push(number);
		}
		else
		{
			std::cerr << RED << "Error: Invalid token in expression => " << token << RESET << std::endl;
		}
	}
	if (_stack.size() != 1)
	{
		std::cerr << RED << "Error: The expression is invalid. Stack size: " << _stack.size() << RESET << std::endl;
		throw RPNException();
	}
	std::cout << _stack.top() << RESET << std::endl;

}

void RPN::operation(char op)
{
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();

	switch (op)
	{
		case '+':
			_stack.push(b + a);
			break;
		case '-':
			_stack.push(b - a);
			break;
		case '*':
			_stack.push(b * a);
			break;
		case '/':
			if (a == 0)
			{
				std::cerr << RED << "Error: Division by zero." << RESET << std::endl;
				_stack.push(b);
				_stack.push(a);
				throw RPNException();
			}
			_stack.push(b / a);
			break;
		default:
			std::cerr << RED << "Error: Unknown operator " << op << RESET << std::endl;
			_stack.push(b);
			_stack.push(a);
			throw RPNException();
	}
}

bool isAllDigits(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}
