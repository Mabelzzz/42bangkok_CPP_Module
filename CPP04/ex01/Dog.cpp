#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	dog_brain = new Brain();
	std::cout << MAGENTA << "Dog recently debuted!!! [Constructor Called]" << RESET << std::endl;
}

Dog::Dog(Dog const &copy)
{
	dog_brain = new Brain();
	*this = copy;
	std::cout << MAGENTA << "Dog Copy Constructor Called" << RESET << std::endl;
}

Dog&	Dog::operator=(Dog const& rhs)
{
	std::cout << MAGENTA << "Dog Assignment Operator Called" << RESET << std::endl;
	if (this != &rhs)
	{
		dog_brain = rhs.dog_brain;
		this->type = rhs.get_type();
	}
	return (*this);
}

Dog::~Dog()
{
	delete dog_brain;
	std::cout << MAGENTA << "Dog has been dead!!! [Destructor Called]" << RESET << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << MAGENTA << "Dog say hong hong... " << RESET << std::endl;
}
