#include "Zombie.hpp"

Zombie::Zombie(){
  std::cout << GREEN << name << " has been created" << std::endl;
}

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

void Zombie::setName(const std::string& name) {
  this->name = name;
}
