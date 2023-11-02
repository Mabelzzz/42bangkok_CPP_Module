#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap mb("Mobile");

	mb.whoAmI();
	mb.takeDamage(10);
	mb.attack("Ghost");
	mb.takeDamage(50);
	mb.guardGate();
	mb.highFivesGuys();

	// DiamondTrap empty("");
	// empty.whoAmI();
}
