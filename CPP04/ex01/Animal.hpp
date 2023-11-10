#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define RESET		"\033[0m"

class Animal
{
	protected:
		std::string		type;

	public:
		Animal();
		Animal(std::string new_type);
		Animal(Animal const &copy);
		Animal&	operator=(Animal const& rhs);
		virtual ~Animal();

		virtual void	makeSound() const;
		std::string	get_type() const;

};

#endif
