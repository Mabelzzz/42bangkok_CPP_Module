#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	cat_brain = new Brain();
	std::cout << BLUE << "Cat recently debuted!!! [Constructor Called]" << RESET << std::endl;
}

Cat::Cat(Cat const &copy)
{
	cat_brain = new Brain();
	*this = copy;
	std::cout << BLUE << "Cat Copy Constructor Called" << RESET << std::endl;
}

Cat&	Cat::operator=(Cat const& rhs)
{
	std::cout << BLUE << "Cat Assignment Operator Called" << RESET << std::endl;

	if (this != &rhs)
	{
		cat_brain = rhs.cat_brain;
		this->type = rhs.get_type();
	}
	return (*this);
}

Cat::~Cat()
{
	delete cat_brain;
	std::cout << BLUE << "Cat has been dead!!! [Destructor Called]" << RESET << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << BLUE << "Cat say meow meowwww!!!" << RESET << std::endl;
}
