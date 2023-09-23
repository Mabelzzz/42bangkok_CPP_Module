#ifndef CONTACT_H
# define CONTACT_H
# include <iostream>
# include <iomanip>
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

class Contact {
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phone;
		std::string secret;

	public:
		Contact();
		~Contact();
		std::string get_firstname(std::string firstname);
		std::string get_lastname(std::string lastname);
		std::string get_nickname(std::string nickname);
		std::string get_phone(std::string phone);
		std::string get_secret(std::string secret);

		// void set_firstname(std::string firstname);
		// void set_lastname(std::string lastname);
		// void set_nickname(std::string nickname);
		// void set_phone(std::string phone);
		// void set_secret(std::string secret);

};

#endif
