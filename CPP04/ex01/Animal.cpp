#include "Animal.hpp"

Animal::Animal():  type("Default")
{
	std::cout << GREEN << "Animal recently debuted!!! [Constructor Called]" << RESET << std::endl;
}

Animal::Animal(std::string new_type): type(new_type)
{
	std::cout << GREEN << "Animal " << this->type << " Constructor Called" << RESET << std::endl;

}

Animal::Animal(Animal const &copy): type(copy.type)
{
	std::cout << GREEN << "Animal Copy Constructor Called" << RESET << std::endl;
}

Animal&	Animal::operator=(Animal const& rhs)
{
	std::cout << GREEN << "Animal Assignment Operator Called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << GREEN << "Animal has been dead!!! [Destructor Called]" << RESET << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << GREEN << "Animal sound ... " << RESET << std::endl;
}

std::string	Animal::get_type() const
{
	return (type);
}
