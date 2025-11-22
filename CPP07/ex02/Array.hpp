#ifndef ARRAY_HPP
# define ARRAY_HPP

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define RESET		"\033[0m"

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;

		unsigned int size() const;

		//Exception class
		class IndexOutOfBoundsException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Index is out of bounds";
				}
		};
};

#include "Array.tpp"

#endif

