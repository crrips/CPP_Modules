#include "HumanA.hpp"

HumanA::HumanA(string name, Weapon &weapon) :  _weapon(weapon), _name(name)
{
}

HumanA::~HumanA()
{
}

void    HumanA::attack(void)
{
    cout << this->_name << " attacks with their " << this->_weapon.getType() << endl;
}
