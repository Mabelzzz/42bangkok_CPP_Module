#include "Zombie.hpp"

int	main()
{
	int	nbr = 12;
	Zombie *zombie = zombieHorde(nbr, "Mabelzzz");
	for(int i = 0; i < nbr; i++)
		zombie[i].announce();
	delete [] zombie;
	return (0);
}
