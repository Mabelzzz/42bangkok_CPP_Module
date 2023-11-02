#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	st("Mobile");

	st.attack("Dragon");

	st.takeDamage(30);
	st.beRepaired(15);
	st.guardGate();
	return 0;
}
