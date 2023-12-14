#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap john("John Cena");
    ClapTrap noname;

    john.attack(noname.getName());
    noname.takeDamage(1);   // hit == 9
    noname.beRepaired(5);   // hit == 14

    john.beRepaired(100);   // hit == 110
    noname.attack(john.getName());
    john.takeDamage(142);   // hit == -32
    john.beRepaired(42);    // hit < 0
    return 0;
}
