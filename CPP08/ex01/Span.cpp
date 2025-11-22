#include "Span.hpp"

Span::Span() : _n(0), _numbers() {
	std::cout << MAGENTA << "Default constructor called" << RESET << std::endl;
}

Span::Span(unsigned int n): _n(n), _numbers() {
	std::cout << MAGENTA << "Parameterized constructor called with n = " << n << RESET << std::endl;
}

Span::Span(const Span& other) : _n(other._n), _numbers(other._numbers) {
	std::cout << MAGENTA << "Copy constructor called" << RESET << std::endl;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->_n = other._n;
		this->_numbers = other._numbers;
	}
	std::cout << BLUE << "Assignment operator called" << RESET << std::endl;
	return *this;
}

Span::~Span() {
	std::cout << GRAY << "Destructor called" << RESET << std::endl;
}

void Span::addNumber(int number) {
	if (this->_numbers.size() >= this->_n) {
		throw SpanFullException();
	} else {
		this->_numbers.push_back(number);
	}
}

unsigned int Span::shortestSpan() {
	std::vector<int> sortedNumbers = checkAndSort();

	unsigned int minSpan = sortedNumbers[1] - sortedNumbers[0];
	for (size_t i = 1; i < sortedNumbers.size(); ++i) {
		unsigned int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

unsigned int Span::longestSpan() {
	std::vector<int> sortedNumbers = checkAndSort();
	return sortedNumbers.back() - sortedNumbers.front();
}

std::vector<int> Span::checkAndSort() {
	if (this->_numbers.size() < 2) {
		throw NotEnoughNumbersException();
	}
	std::vector<int> sortedNumbers = this->_numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	return sortedNumbers;
}
