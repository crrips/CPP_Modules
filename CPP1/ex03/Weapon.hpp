#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Weapon
{
private:
	string _type;
	
public:
	Weapon(string type);
	~Weapon(void);

	const string &getType(void) const;
	void setType(string type);
};

#endif