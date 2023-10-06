#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Zombie
{
private:
	string _name;

public:
	Zombie(string name);
	Zombie(void){};
	~Zombie(void);

	void announce(void);
	void setName(string name);
};

#endif