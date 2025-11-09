#include "Base.hpp"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	std::cout << "-- Generating Instance --" << std::endl;
	Base* ptr = generate();

	std::cout << "-- Identification by Pointer --" << std::endl;
	identify(ptr);

	std::cout << "-- Identification by Reference --" << std::endl;
	identify(*ptr);

	std::cout << "-- Cleanup --" << std::endl;
	delete ptr;
	return 0;
}
