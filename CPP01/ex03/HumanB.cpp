#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _weapon(NULL), _name(name)
{
}

HumanB::HumanB(std::string name, Weapon &weapon) : _weapon(&weapon), _name(name)
{
}

HumanB::~HumanB()
{
}

void    HumanB::attack(void)
{
    if (this->_weapon != NULL)
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}