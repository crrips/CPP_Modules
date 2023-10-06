#include "Zombie.hpp"

Zombie *zombieHorde(int N, string name)
{
    Zombie *horde = new Zombie[N];
    while (N--)
        horde[N].setName(name);
    return horde;
}
