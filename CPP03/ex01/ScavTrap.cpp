# include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy)
{
	*this = copy;
	std::cout << "ScavTrap Copy Constructor Called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const& rhs)
{
	std::cout << "ScavTrap Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_HitPoint = rhs._HitPoint;
		this->_EnergyPoint = rhs._EnergyPoint;
		this->_AttackDamage = rhs._AttackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_EnergyPoint > 0 && _HitPoint > 0)
	{
		_EnergyPoint -= 1;
		std::cout << "ScavTrap " << _name;
		std::cout << " attacks " << target;
		std::cout << " causing " << _AttackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap cannot attack 'cuz there is not enough point." << std::endl;
}
