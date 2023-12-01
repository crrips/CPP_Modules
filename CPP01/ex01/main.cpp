#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main()
{
	Zombie *horde = zombieHorde(10, "Zombie");
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	delete[] horde;
	horde = zombieHorde(10, "new Zombie");
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	delete[] horde;
	system("leaks Zombie");
	return 0;
}