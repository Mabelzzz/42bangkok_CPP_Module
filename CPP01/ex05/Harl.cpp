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

void	Harl::complain(std::string level)
{
		std::string _lv[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		void (Harl::*_funcs[4])(void) = { &Harl::debug,  &Harl::info,  &Harl::warning,  &Harl::error};
		for (int i = 0; i < 4; i++)
		{
		if (str_upper(level) == _lv[i])
		{
			std::cout << BOLD << "[ " + _lv[i] + " ]" << std::endl;
			(this->*_funcs[i])();
		}
		}
}
