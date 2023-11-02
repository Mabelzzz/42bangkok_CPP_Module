#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string		_type;

	public:
		Animal(std::string type);
		Animal(Animal const &copy);
		Animal&	operator=(Animal const& rhs);
		~Animal();

		void	makeSound();

};

#endif
