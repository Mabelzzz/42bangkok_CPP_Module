#include <iostream>
#include <cctype>

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

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << RED << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	for(int i = 1; i < argc; i++)
	{
		for(int j = 0; argv[i][j]; j++)
			std::cout << BLUE << (char)toupper(argv[i][j]);
	}
	if (argc > 1)
		std::cout << std::endl;
	return (0);
}
