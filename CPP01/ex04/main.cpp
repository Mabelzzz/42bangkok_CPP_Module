#include "Sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << RED << "Error: Invalid Parameters! " << RESET << std::endl;
		return (1);
	}
	Sed sed(argv[1], argv[2], argv[3]);


	sed.get_data();
	sed.replace_str();
	if (sed.create_outfile() == 1)
		std::cerr << RED << "Cannot create outfile" << std::endl;
	return (0);
}
