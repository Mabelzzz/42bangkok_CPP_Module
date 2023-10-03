#include "Sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << RED << "Error: Invalid Parameters! " << RESET << std::endl;
		return (1);
	}
	std::ifstream ifs (argv[1]);
	if(ifs.is_open())
		
	std::cout << ifs.is_open() << std::endl;
	return (0);
}
