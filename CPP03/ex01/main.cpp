#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap john("John Cena");
    ScavTrap aboba("Aboba");

    john.attack(aboba.getName());
    aboba.takeDamage(10);
    aboba.guardGate();
    john.attack(aboba.getName());
    aboba.takeDamage(10);
    aboba.attack(john.getName());
    john.takeDamage(20);
    return 0;
}
