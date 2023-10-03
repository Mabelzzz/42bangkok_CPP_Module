#include "Harl.hpp"

Harl::Harl() {

}

Harl::~Harl() {

}

void	Harl::debug()
{
	std::cout << GREEN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << RESET << std::endl;
}

void	Harl::info()
{
	std::cout << CYAN << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
}

void	Harl::warning()
{
	std::cout << YELLOW << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << RESET << std::endl;
}

void	Harl::error()
{
	std::cout << MAGENTA << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

std::string Harl::str_upper(std::string str)
{
	for (int i = 0; str[i]; i++)
		str[i] = (char)toupper(str[i]);
	return (str);
}

int	Harl::find_level(std::string level)
{
		std::string _lv[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		for (int i = 0; i < 4; i++)
		{
			if (str_upper(level) == _lv[i])
				return (i);
		}
		return (-1);
}

void	Harl::complain(int level)
{
	std::string _lv[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*_funcs[4])(void) = { &Harl::debug,  &Harl::info,  &Harl::warning,  &Harl::error};

	if (level < 0 || level > 4)
		return ;
	std::cout << BOLD << "[ " + _lv[level] + " ]" << std::endl;
	(this->*_funcs[level])();
}

void	Harl::harlFilter(std::string funcs)
{
	int	level = find_level(funcs);

	switch (level)
	{
		case 0:
			complain(level++);
			std::cout << std::endl;
		case 1:
			complain(level++);
			std::cout << std::endl;
		case 2:
			complain(level++);
			std::cout << std::endl;
		case 3:
			complain(level++);
			break;
		default:
			std::cout << RED << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
