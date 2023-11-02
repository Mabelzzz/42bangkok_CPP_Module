# include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_HitPoint = 100;
	this->_EnergyPoint = 100;
	this->_AttackDamage = 30;
	std::cout << "FragTrap Constructor Called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy): ClapTrap(copy)
{
	std::cout << "FragTrap Copy Constructor Called" << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap const& rhs)
{
	std::cout << "FragTrap Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_HitPoint = rhs._HitPoint;
		this->_EnergyPoint = rhs._EnergyPoint;
		this->_AttackDamage = rhs._AttackDamage;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor Called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap have a positive HIGHT FIVE!!!" << std::endl;
}
