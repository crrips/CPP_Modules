#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main()
{
	int N = 5;

	if (N <= 0)
	{
		std::cout << "N must be positive" << std::endl;
		return 1;
	}
	Zombie *horde = zombieHorde(N, "Zombie");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	horde = zombieHorde(N, "new Zombie");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	// system("leaks Zombie");
	return 0;
}