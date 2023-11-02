#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	mb("Mobile");

	mb.attack("Dragon");
	mb.takeDamage(30);
	mb.beRepaired(15);

	return 0;
}
