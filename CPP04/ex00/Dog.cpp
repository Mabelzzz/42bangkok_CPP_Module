#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << MAGENTA << "Dog recently debuted!!! [Constructor Called]" << RESET << std::endl;
}

Dog::Dog(Dog const &copy)
{
	*this = copy;
	std::cout << MAGENTA << "Dog Copy Constructor Called" << RESET << std::endl;
}

Dog&	Dog::operator=(Dog const& rhs)
{
	std::cout << MAGENTA << "Dog Assignment Operator Called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.get_type();
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << MAGENTA << "Dog has been dead!!! [Destructor Called]" << RESET << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << MAGENTA << "Dog say hong hong... " << RESET << std::endl;
}
