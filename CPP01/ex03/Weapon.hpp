#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

using std::std::cout;
using std::std::endl;
using std::std::string;

class Weapon
{
private:
	std::string _type;
	
public:
	Weapon(std::string type);
	~Weapon(void);

	const std::string &getType(void) const;
	void setType(std::string type);
};

#endif