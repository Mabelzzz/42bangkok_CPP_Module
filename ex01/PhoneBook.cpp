
#include "PhoneBook.hpp"

int		PhoneBook::check_empty_str(std::string str)
{
	// if (!str || !str[0])
	// 	return (0);
	str.c_str();
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != " ")
			return (1);
	}
	return (0);
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
			break;
	}
	return (ans);
}

void	PhoneBook::add_contact()
{
	std::cout << get_info("Enter your FirstName: ") << std::endl;
	std::cout << get_info("Enter your LastName: ") << std::endl;
}

void	PhoneBook::search_contact()
{
	std::cout << RED << "search_contact" << RESET << std::endl;
}
