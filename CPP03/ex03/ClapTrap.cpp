# include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0)
{
	std::cout << "ClapTrap Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy): _name(copy._name), _HitPoint(copy._HitPoint), _EnergyPoint(copy._EnergyPoint), _AttackDamage(copy._AttackDamage)
{
	std::cout << "ClapTrap Copy Constructor Called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const& rhs)
{
	std::cout << "ClapTrap Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_HitPoint = rhs._HitPoint;
		this->_EnergyPoint = rhs._EnergyPoint;
		this->_AttackDamage = rhs._AttackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor Called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_EnergyPoint > 0 && _HitPoint > 0)
	{
		_EnergyPoint -= 1;
		std::cout << "ClapTrap " << _name;
		std::cout << " attacks " << target;
		std::cout << " causing " << _AttackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap cannot attack 'cuz there is not enough point." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_HitPoint > 0)
	{
		if (_HitPoint < amount)
			_HitPoint = 0;
		else
			_HitPoint -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!";
		std::cout << " Hit point = " << _HitPoint << std::endl;
	}
	else
		std::cout << "ClapTrap cannot take damage 'cuz there is not enough point." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoint > 0 && _HitPoint > 0)
	{
		_EnergyPoint -= 1;
		_HitPoint += amount;
		std::cout << "ClapTrap " << _name << " has been repaired for "  << amount << " points!";
		std::cout << " Hit point = " << _HitPoint << std::endl;
	}
	else
		std::cout << "ClapTrap cannot be repaired 'cuz there is not enough point." << std::endl;
}

