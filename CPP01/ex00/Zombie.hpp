#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

using std::std::cout;
using std::std::endl;
using std::std::string;

class Zombie
{
private:
	std::string _name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void announce(void);
	void newZombie(std::string name);
	void randomChump();
};

#endif