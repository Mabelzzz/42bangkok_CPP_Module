#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) : name(name){
  std::cout << GREEN << name << " constructed" << std::endl;
}

Zombie::~Zombie() {
  std::cout << RED << name << " deconstructed" << std::endl;
}

void	Zombie::announce()
{
	std::cout << CYAN<< name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
