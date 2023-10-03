#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

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

class Harl {
	private:
		// std::string _lv[4];
		// void	(Harl::*_funcs[4])(void);
		void	debug();
		void	info();
		void	warning();
		void	error();
		std::string str_upper(std::string str);

	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif
