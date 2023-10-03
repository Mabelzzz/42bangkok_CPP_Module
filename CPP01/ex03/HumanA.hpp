#ifndef HUMANA_H
# define HUMANA_H

# include <iostream>
# include <string>
#include "Weapon.hpp"

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define GRAY		"\033[0;37m"
# define LRED		"\033[0;91m"
# define BOLD		"\033[1m"
# define RESET		"\033[0m"

class HumanA {
	private:
		std::string _name;
		const Weapon& _weapon;
	public:
		HumanA(const std::string& name, const Weapon& weapon);
		~HumanA();

		void	attack();
};

#endif
