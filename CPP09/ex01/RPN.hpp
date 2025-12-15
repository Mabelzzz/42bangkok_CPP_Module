#ifndef RPN_HPP
#define RPN_HPP

# define RED		"\033[0;31m"
# define RESET		"\033[0m"

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <exception>

class RPN
{
	private:
		std::stack<int> _stack;
		void operation(char op);

	public:
		RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& other);
		~RPN();

		void calculate(const std::string& expression);

	class RPNException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "RPN Error";
			}
    };

};

bool isAllDigits(const std::string& str);

#endif
