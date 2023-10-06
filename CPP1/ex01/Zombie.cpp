#include "Zombie.hpp"

Zombie::Zombie(string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	cout << this->_name << ": BraiiiiiiinnnzzzZ..." << endl;
}

Zombie::~Zombie()
{
	cout << this->_name << ": is dead 💀" << endl;
}

void	Zombie::setName(string name)
{
	this->_name = name;
}