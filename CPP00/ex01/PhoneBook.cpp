
#include "PhoneBook.hpp"

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

void		PhoneBook::set_info(std::string ans, int i)
{
	int	index = 0;

	if (i == 1)
		this->contact[index].set_firstname(ans);
	if (i == 2)
		this->contact[index].set_lastname(ans);
	if (i == 3)
		this->contact[index].set_nickname(ans);
	if (i == 4)
		this->contact[index].set_phone(ans);
	if (i == 5)
		this->contact[index].set_secret(ans);
}

std::string		PhoneBook::get_info(std::string ask)
{
	std::string ans;

	while (1)
	{
		std::cout << BOLD << ask , std::getline (std::cin, ans);
		if (!check_empty_str(ans))
			std::cout << RED << "Invalid answer, pls try agian!" << RESET << std::endl;
		else
			break ;
	}
	return (ans);
}

void	PhoneBook::add_contact()
{
	set_info(get_info("Enter your FirstName: "), 1);
	set_info(get_info("Enter your LastName: "), 2);
	set_info(get_info("Enter your Nickname: "), 3);
	set_info(get_info("Enter your Phone: "), 4);
	set_info(get_info("Enter your DarkSecret: "), 5);
}

void	PhoneBook::search_contact()
{
	std::cout << RED << "search_contact" << RESET << std::endl;
	std::cout << BOLD << " __________ __________ __________ __________ " << RESET << std::endl;
	std::cout << BOLD << "┏━━━━━━━━━━┏━━━━━━━━━━┏━━━━━━━━━━┏━━━━━━━━━━┓" << RESET << std::endl;
	std::cout << BOLD << "┃     index┃ firstname┃  lastname┃  nickname┃" << RESET << std::endl;
	std::cout << BOLD << "┗━━━━━━━━━━┛━━━━━━━━━━┛━━━━━━━━━━┛━━━━━━━━━━┛" << RESET << std::endl;
	std::cout << BOLD << "┃     index┃ firstname┃  lastname┃  nickname┃" << RESET << std::endl;
	std::cout << BOLD << "┗━━━━━━━━━━┛━━━━━━━━━━┛━━━━━━━━━━┛━━━━━━━━━━┛" << RESET << std::endl;
	std::cout << BOLD << "┃     index┃ firstname┃  lastname┃  nickname┃" << RESET << std::endl;
	std::cout << BOLD << "┗━━━━━━━━━━┛━━━━━━━━━━┛━━━━━━━━━━┛━━━━━━━━━━┛" << RESET << std::endl;
	//   index, firstname, lastname, nickname
	┏━━━━  ━  ━  ━  ━  ━  ━  ━  ━  ┓
 | ━  ━  ━  ━  ━  ━  ━  ━  ━  ━  ━  ━  ━ ┃
┗━━━━━━━  ━  ━  ━  ━  ━  ━ ┛
}
