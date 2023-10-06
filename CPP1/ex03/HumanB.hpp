#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
    Weapon  *_weapon;
    string  _name;

public:
    HumanB(string name);
    HumanB(string name, Weapon &weapon);
    ~HumanB(void);

    void    attack(void);
    void    setWeapon(Weapon &weapon);
};

#endif