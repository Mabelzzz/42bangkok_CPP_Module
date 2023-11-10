#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << YELLOW << "WrongCat recently debuted!!! [Constructor Called]" << RESET << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy)
{
	*this = copy;
	std::cout << YELLOW << "WrongCat Copy Constructor Called" << RESET << std::endl;
}

WrongCat&	WrongCat::operator=(WrongCat const& rhs)
{
	std::cout << YELLOW << "WrongCat Assignment Operator Called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.get_type();
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << YELLOW << "WrongCat has been dead!!! [Destructor Called]" << RESET << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << YELLOW << "WrongCat say meow meow... " << RESET << std::endl;
}
