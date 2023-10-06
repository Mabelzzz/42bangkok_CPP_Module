#ifndef SED_H
# define SED_H

# include <iostream>
# include <string>
#include <fstream>

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

class Sed {
	private:
		size_t			cur;
		std::string		s1;
		std::string		s2;
		std::string		str;
		std::string		data;
		std::string		filename;
		std::ofstream	outfile;
		std::ifstream	infile;

	public:
		Sed();
		Sed(const std::string& infile, const std::string& s1, const std::string& s2);
		~Sed();
		void	get_data();
		void	replace_str();
		int	create_outfile();

};

#endif
