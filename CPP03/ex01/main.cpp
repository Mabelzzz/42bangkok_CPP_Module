#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
        ClapTrap a("Tatar");
        ScavTrap scav("Fah"); // Creates a ScavTrap

        scav.attack("Tatar");
        a.takeDamage(20);
		std::cout << std::endl;

		a.attack("Fah");
        scav.beRepaired(10);
        scav.guardGate();
		std::cout << std::endl;
}

