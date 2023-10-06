#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
    Weapon  &_weapon;
    string  _name;

public:
    HumanA(string name, Weapon &weapon);
    ~HumanA(void);

    void    attack(void);
};

#endif