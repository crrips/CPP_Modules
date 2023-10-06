#include "HumanB.hpp"

HumanB::HumanB(string name) : _weapon(NULL), _name(name)
{
}

HumanB::HumanB(string name, Weapon &weapon) : _weapon(&weapon), _name(name)
{
}

HumanB::~HumanB()
{
}

void    HumanB::attack(void)
{
    if (this->_weapon != NULL)
        cout << this->_name << " attacks with their " << this->_weapon->getType() << endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}