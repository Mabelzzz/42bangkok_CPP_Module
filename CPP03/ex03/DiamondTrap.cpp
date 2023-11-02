# include "DiamondTrap.hpp"
# include "ClapTrap.hpp"

DiamondTrap::DiamondTrap(): _name(""), ClapTrap(""), ScavTrap(""), FragTrap("")
{
	this->_HitPoint = FragTrap::_HitPoint;
	this->_EnergyPoint = 50;
	this->_AttackDamage = FragTrap::_AttackDamage;
	std::cout << "DiamondTrap NoName Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):  _name(name), ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	ClapTrap::_name.append("_clap_name");
	this->_HitPoint = FragTrap::_HitPoint;
	this->_EnergyPoint = 50;
	this->_AttackDamage = FragTrap::_AttackDamage;
	std::cout << "DiamondTrap " << this->_name << " Constructor Called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor Called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
		std::cout << "Name of DiamondTrap is " << this->_name << std::endl;
		std::cout << "Name of ClapTrap is " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string &target){
	ScavTrap::attack( target );
}
