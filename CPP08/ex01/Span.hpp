#ifndef SPAN_HPP
# define SPAN_HPP

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define GRAY		"\033[0;90m"
# define RESET		"\033[0m"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm> // std::sort

class Span {
	private:
		unsigned int _n;
		std::vector<int> _numbers;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		std::vector<int> checkAndSort();

		template <typename Iterator>
		void addManyNumbers(Iterator begin, Iterator end) {
			unsigned int amount = std::distance(begin, end);

			if (this->_numbers.size() + amount > this->_n) {
				throw SpanFullException();
			}

			this->_numbers.insert(this->_numbers.end(), begin, end);
		}

		//Exception
		class SpanFullException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Span is already full";
				}
		};

		class NotEnoughNumbersException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Not enough numbers to calculate a span";
				}
		};

};

#endif
