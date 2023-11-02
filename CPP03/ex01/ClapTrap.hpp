#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_HitPoint;
		unsigned int	_EnergyPoint;
		unsigned int	_AttackDamage;

	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &copy);
		ClapTrap&	operator=(ClapTrap const& rhs);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

};

#endif
