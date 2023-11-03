#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string		type;

	public:
		Animal();
		Animal(std::string new_type);
		Animal(Animal const &copy);
		Animal&	operator=(Animal const& rhs);
		~Animal();

		void	makeSound();
		std::string	get_type();

};

#endif
