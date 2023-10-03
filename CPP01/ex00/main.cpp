#include "Zombie.hpp"

int	main()
{
	{
		Zombie zombie("Mobile");
		zombie.announce();
	}
	{
		Zombie *zombie = newZombie("New Mobile");
		zombie->announce();
		delete zombie;
	}
	{
		randomChump("Mobile Chump");
	}
}
