#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

# define MaxContact 8

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

class PhoneBook {
	private:
		Contact contact[MaxContact];
		int		cur;

	public:
		void	add_contact(int index);
		void	search_contact();
		int		check_empty_str(std::string str);
		int		check_nbr(std::string str);
		std::string		get_info(std::string ask, int mode);
		void		sub_str(std::string str);
		void	print_contact(int index);
		// void	set_info(std::string ans, int i);


};

#endif
