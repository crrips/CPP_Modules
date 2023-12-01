#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	Zombie	zombie_stack("Zombie Stack");
	Zombie	*zombie_heap = newZombie("Zombie Heap");
	zombie_stack.announce();
	zombie_heap->announce();
	delete zombie_heap;
	randomChump("Zombie Random");
	zombie_heap = newZombie("Zombie Heap");
	zombie_heap->announce();
	delete zombie_heap;
	return 0;
}