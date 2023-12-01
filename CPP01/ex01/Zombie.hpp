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
	Zombie(std::string name);
	Zombie(void){};
	~Zombie(void);

	void announce(void);
	void setName(std::string name);
};

#endif