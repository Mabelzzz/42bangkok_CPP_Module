#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define RESET		"\033[0m"

#include <iostream>
#include <algorithm> //std::find
#include <stdexcept> //std::exception

class NotFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Value not found in the container";
		}
};

template <typename T>
typename T::iterator easyfind(T& container, int n) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end()) {
		throw NotFoundException();
	} else {
		std::cout << GREEN << "Value " << n << " found!" << RESET << std::endl;
	}

	return it;
}

#endif
