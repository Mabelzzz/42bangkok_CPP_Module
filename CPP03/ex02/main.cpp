#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	ft("Mobile");

	ft.attack("Dragon");
	ft.takeDamage(300);
	ft.beRepaired(150);
	ft.highFivesGuys();
	return 0;
}
