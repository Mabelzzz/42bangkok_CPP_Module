#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define RESET		"\033[0m"

class WrongAnimal
{
	protected:
		std::string		type;

	public:
		WrongAnimal();
		WrongAnimal(std::string new_type);
		WrongAnimal(WrongAnimal const &copy);
		WrongAnimal&	operator=(WrongAnimal const& rhs);
		virtual ~WrongAnimal();

		void	makeSound() const;
		std::string	get_type() const;

};

#endif
