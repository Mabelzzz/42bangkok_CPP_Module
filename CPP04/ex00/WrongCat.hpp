#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include"WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &copy);
		WrongCat& operator=(WrongCat const& rhs);
		~WrongCat();

		void	makeSound() const;
};

#endif
