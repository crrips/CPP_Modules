#include "Zombie.hpp"

Zombie::Zombie(string name)
{
    _name = name;
}

void    Zombie::announce(void)
{
    cout << _name << ": BraiiiiiiinnnzzzZ..." << endl;
}

Zombie::~Zombie()
{
    cout << _name << ": is dead 💀" << endl;
}
