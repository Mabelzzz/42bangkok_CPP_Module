#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():  type("Default")
{
	std::cout << RED << "WrongAnimal recently debuted!!! [Constructor Called]" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string new_type): type(new_type)
{
	std::cout << RED << "WrongAnimal " << this->type << " Constructor Called" << RESET << std::endl;

}

WrongAnimal::WrongAnimal(WrongAnimal const &copy): type(copy.type)
{
	std::cout << RED << "WrongAnimal Copy Constructor Called" << RESET << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& rhs)
{
	std::cout << RED << "WrongAnimal Assignment Operator Called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal has been dead!!! [Destructor Called]" << RESET << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << RED << "WrongAnimal sound ... " << RESET << std::endl;
}

std::string	WrongAnimal::get_type() const
{
	return (type);
}
