#include "HumanB.hpp"

HumanB::HumanB(const std::string& name): _name(name) {
}

HumanB::~HumanB() {

}

void	HumanB::attack()
{
	if (!this->_weapon)
		std::cout << MAGENTA << this->_name << " don't have weapon" << RESET << std::endl;
	else
		std::cout << MAGENTA << this->_name << " attacks with their " << this->_weapon->getType() << RESET << std::endl;
}

void HumanB::setWeapon(const Weapon& weapon)
{
  this->_weapon = &weapon;
}
