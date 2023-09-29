
#include "Phonebook.hpp"

int		PhoneBook::check_empty_str(std::string str)
{
	// if (!str || !str[0])
	// 	return (0);
	str.c_str();
	// for (int i = 0; str[i]; i++)
	// {
	// 	if (str[i] != " ")
	// 		return (1);
	// }
	return (1);
}

int		PhoneBook::check_nbr(std::string str)
{

	str.c_str();

	return (1);
}

// void		PhoneBook::set_info(std::string ans, int i)
// {
// 	int	index = 0;

// 	if (i == 1)
// 		this->contact[this->cur].set_firstname(ans);
// 	if (i == 2)
// 		this->contact[index].set_lastname(ans);
// 	if (i == 3)
// 		this->contact[index].set_nickname(ans);
// 	if (i == 4)
// 		this->contact[index].set_phone(ans);
// 	if (i == 5)
// 		this->contact[index].set_secret(ans);
// }

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
	this->contact[index].set_firstname(get_info("Enter your FirstName: ", 1));
	this->contact[index].set_lastname(get_info("Enter your LastName: ", 1));
	this->contact[index].set_nickname(get_info("Enter your Nickname: ", 1));
	this->contact[index].set_phone(get_info("Enter your Phone: ", 1));
	this->contact[index].set_secret(get_info("Enter your DarkSecret: ", 1));
	print_contact(index);
}

void	PhoneBook::print_contact(int index)
{
		std::cout << BLUE << "┏━━━━━━━━━━┓━━━━━━━━━━┓━━━━━━━━━━┓━━━━━━━━━━┏━━━━━━━━━━┏━━━━━━━━━━┓" << RESET << std::endl;
		std::cout << BOLD << "┃     index┃ firstname┃  lastname┃  nickname┃     phone┃    secret┃" << RESET << std::endl;
		std::cout << BLUE << "┗━━━━━━━━━━┗━━━━━━━━━━┗━━━━━━━━━━┗━━━━━━━━━━┗━━━━━━━━━━┗━━━━━━━━━━┛" << RESET << std::endl;
	for (int i = 0; i <= index; i++)
	{
		// sub_str(i - '0');
		std::cout << std::left << std::setw(1) << "┃"
							<< std::right << std::setw(10) << std::to_string(i);
		sub_str(this->contact[i].get_firstname());
		sub_str(this->contact[i].get_lastname());
		sub_str(this->contact[i].get_nickname());
		sub_str(this->contact[i].get_phone());
		sub_str(this->contact[i].get_secret());
		std::cout << "┃" << std::endl;
		std::cout << BLUE << "┗━━━━━━━━━━┗━━━━━━━━━━┗━━━━━━━━━━┗━━━━━━━━━━┗━━━━━━━━━━┗━━━━━━━━━━┛" << RESET << std::endl;
	}
}

void	PhoneBook::sub_str(std::string str)
{
	int len = str.length();
	// std::cout << len << " .  " + str << std::endl;
	if (len > 10)
		str = str.substr(0, 9) + '.';
		// std::cout << str.substr(0, 9) + "." << std::endl;
		// return (str.substr(0, 9) + ".");
	// else
	// 	std::cout << str.insert(10 - len, " ") << std::endl;
		// return (str.insert(10 - len, " "));

		std::cout << std::left << std::setw(1) << "┃"
							<< std::right << std::setw(10) << str;
		// std::cout << "---------------------------------------------------------------------"<< std::endl;
	// return (str);

}

void	PhoneBook::search_contact()
{
	int index = 0;
	//while loop cout
		std::cout << RED << "search_contact" << RESET << std::endl;
		// std::cout << BOLD << get_info("Enter index: ", 2) << std::endl;
		// std::cout << this->contact[index].get_firstname().substr(0, 9) + "." << std::endl;
		// std::cout << BOLD << "|----------|----------|----------|----------|----------|" << RESET << std::endl;
		std::cout << BOLD << "┏━━━━━━━━━━┏━━━━━━━━━━┏━━━━━━━━━━┏━━━━━━━━━━┓" << RESET << std::endl;
	// for (int i = 0; i < 2; i++)
	// {
		sub_str(get_info("Enter index: ", 2));
		sub_str(this->contact[index].get_firstname());
		sub_str(this->contact[index].get_lastname());
		sub_str(this->contact[index].get_nickname());
		std::cout << "┃" << std::endl;
		std::cout << BOLD << "┗━━━━━━━━━━┛━━━━━━━━━━┛━━━━━━━━━━┛━━━━━━━━━━┛" << RESET << std::endl;
		// std::cout << BOLD << "|----------|----------|----------|----------|----------|" << RESET << std::endl;
	// }

	// std::cout << BOLD << " __________ __________ __________ __________ " << RESET << std::endl;
	// .substr(0, 10)
	// std::cout << BOLD << "┏━━━━━━━━━━┏━━━━━━━━━━┏━━━━━━━━━━┏━━━━━━━━━━┓" << RESET << std::endl;
	// std::cout << BOLD << "┃     index┃ firstname┃  lastname┃  nickname┃" << RESET << std::endl;
	// std::cout << BOLD << "┗━━━━━━━━━━┛━━━━━━━━━━┛━━━━━━━━━━┛━━━━━━━━━━┛" << RESET << std::endl;
	// std::cout << BOLD << "┃     index┃ firstname┃  lastname┃  nickname┃" << RESET << std::endl;
	// std::cout << BOLD << "┗━━━━━━━━━━┛━━━━━━━━━━┛━━━━━━━━━━┛━━━━━━━━━━┛" << RESET << std::endl;
	// std::cout << BOLD << "┃     index┃ firstname┃  lastname┃  nickname┃" << RESET << std::endl;
	// std::cout << BOLD << "┗━━━━━━━━━━┛━━━━━━━━━━┛━━━━━━━━━━┛━━━━━━━━━━┛" << RESET << std::endl;
	//   index, firstname, lastname, nickname
// 	┏━━━━  ━  ━  ━  ━  ━  ━  ━  ━  ┓
//  | ━  ━  ━  ━  ━  ━  ━  ━  ━  ━  ━  ━  ━ ┃
// ┗━━━━━━━  ━  ━  ━  ━  ━  ━ ┛
}
