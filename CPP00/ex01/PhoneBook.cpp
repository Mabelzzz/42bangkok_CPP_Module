#include "Phonebook.hpp"

int		PhoneBook::check_empty_str(std::string str)
{
	int empty = 0;
	str.c_str();
	for (int i = 0; str[i]; i++)
	{
		if (isspace(str[i]))
			empty++;
	}
	if (empty == str.length())
		return (0);
	return (1);
}

int		PhoneBook::check_nbr(std::string str)
{
	str.c_str();
	for(int i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]))
		{
			std::cout << RED << "Invalid number" << RESET << std::endl;
			return (0);
		}
	}
	return (1);
}

std::string		PhoneBook::get_info(std::string ask, int mode)
{
	std::string ans;

	while (1)
	{
		std::cout << BOLD << ask , std::getline (std::cin, ans);
		if (mode == 1 && !check_empty_str(ans))
			std::cout << RED << "Invalid answer, pls try agian!" << RESET << std::endl;
		else if (mode == 2 && !check_empty_str(ans) && !check_nbr(ans))
			std::cout << RED << "Invalid index, pls try agian!" << RESET << std::endl;
		else
			break ;
	}
	return (ans);
}

void	PhoneBook::add_contact(int index)
{
	// this->cur = index;
	this->contact[index % 8].set_firstname(get_info("Enter your FirstName: ", 1));
	this->contact[index % 8].set_lastname(get_info("Enter your LastName: ", 1));
	this->contact[index % 8].set_nickname(get_info("Enter your Nickname: ", 1));
	this->contact[index % 8].set_phone(get_info("Enter your Phone: ", 1));
	this->contact[index % 8].set_secret(get_info("Enter your DarkSecret: ", 1));
}

void	PhoneBook::print_contact(int index)
{
		if (index > 7)
			index = 7;
		else
			index--;
		std::cout << YELLOW << "┏━━━━━━━━━━┓━━━━━━━━━━┓━━━━━━━━━━┓━━━━━━━━━━┓" << RESET << std::endl;
		std::cout << YELLOW << "┃     index┃ firstname┃  lastname┃  nickname┃" << RESET << std::endl;
		std::cout << YELLOW << "┗━━━━━━━━━━┗━━━━━━━━━━┗━━━━━━━━━━┗━━━━━━━━━━┛" << RESET << std::endl;
	for (int i = 0; i <= index; i++)
	{
		std::cout << MAGENTA << std::left << std::setw(1) << "┃";
		std::cout << CYAN << std::right << std::setw(10) << std::to_string(i);
		sub_str(this->contact[i].get_firstname());
		sub_str(this->contact[i].get_lastname());
		sub_str(this->contact[i].get_nickname());
		std::cout << MAGENTA << "┃" << std::endl;
		std::cout << MAGENTA << "┗━━━━━━━━━━┗━━━━━━━━━━┗━━━━━━━━━━┗━━━━━━━━━━┛" << RESET << std::endl;
	}
}

void	PhoneBook::sub_str(std::string str)
{
	int len = str.length();

	if (len > 10)
		str = str.substr(0, 9) + '.';
		std::cout << MAGENTA << std::left << std::setw(1) << "┃";
		std::cout << CYAN << std::right << std::setw(10) << str;
}

int		PhoneBook::check_index(std::string search)
{
	int		idx;

	search.c_str();
	for(int i = 0; search[i]; i++)
	{
		if (!isdigit(search[i]))
		{
			std::cout << RED << "Invalid number" << RESET << std::endl;
			return (-1);
		}
	}
	idx = search[0] - '0';
	if (search.length() == 1 && idx >= 0 && idx < 8)
		return (idx);
	std::cout << RED << "Out 0f range" << RESET << std::endl;

	return (-1);
}

void	PhoneBook::search_contact(int index)
{
	std::string search;
	int	input;

	std::cout << BLUE << "All contact" << RESET << std::endl;
	print_contact(index);
	std::cout << BOLD << "Enter index: " , std::getline (std::cin, search);
	input = check_index(search);
	if (input >= 0)
	{
		if (input > index - 1)
			std::cout << RED << "Empty Contact" << RESET << std::endl;
		std::cout << BOLD << "Index: " << CYAN << this->contact[input].get_firstname() << RESET << std::endl;
		std::cout << BOLD << "Firstname: " << CYAN << this->contact[input].get_firstname() << RESET << std::endl;
		std::cout << BOLD << "Lastname: " << CYAN << this->contact[input].get_lastname() << RESET << std::endl;
		std::cout << BOLD << "Nickname: " << CYAN << this->contact[input].get_nickname() << RESET << std::endl;
		std::cout << BOLD << "Phone: " << CYAN << this->contact[input].get_phone() << RESET << std::endl;
		std::cout << BOLD << "DarkSecret: " << CYAN << this->contact[input].get_secret() << RESET << std::endl;
		std::cout << GREEN << "Search contact succesful" << RESET << std::endl;
	}
}
