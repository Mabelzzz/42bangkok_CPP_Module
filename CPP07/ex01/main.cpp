#include "iter.hpp"

template <typename T>
void printElement(T &any)
{
	std::cout << any << " ";
}

void addFive(int &n)
{
	n += 5;
}

int main( void )
{
	int nbr[] = {3, 5, 7, 9, 11};

	std::cout << "Original array: ";
	::iter(nbr, 5, printElement<int>);
	std::cout << std::endl;

	::iter(nbr, 5, addFive);
	std::cout << YELLOW << "After adding five: ";
	::iter(nbr, 5, printElement<int>);
	std::cout << RESET << std::endl;

	std::string fruits[] = {"apple", "banana", "cherry"};
	std::cout << "Fruits array: ";
	::iter(fruits, 3, ::printElement<std::string>);
	std::cout << std::endl;

	return 0;
}
