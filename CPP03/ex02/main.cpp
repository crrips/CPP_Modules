#include "FragTrap.hpp"

int main(void)
{
    ClapTrap john("John Cena");
    ScavTrap aboba("Aboba");
    FragTrap messi("Messi");

    john.attack(aboba.getName());
    aboba.takeDamage(10);
    aboba.guardGate();
    john.attack(aboba.getName());
    aboba.takeDamage(10);
    aboba.attack(john.getName());
    john.takeDamage(20);
    john.attack(messi.getName());
    messi.takeDamage(10);
    messi.beRepaired(20);
    messi.attack(aboba.getName());
    aboba.takeDamage(5);
    messi.highFivesGuys();
    return 0;
}
