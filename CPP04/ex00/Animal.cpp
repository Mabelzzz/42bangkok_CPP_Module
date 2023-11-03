#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Constructor Called" << std::endl;
}

Animal::Animal(std::string new_type): type(new_type)
{
	std::cout << "Animal " << this->type << " Constructor Called" << std::endl;

}

Animal::Animal(Animal const &copy)
{

}

Animal::Animal&	operator=(Animal const& rhs)
{

}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called" << std::endl;
}

void	Animal::makeSound()
{
	std::cout << "Animal sound ... " << std::endl;
}

std::string	Animal::get_type()
{
	return (type);
}
