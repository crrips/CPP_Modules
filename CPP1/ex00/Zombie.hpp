#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

using std::cout;
using std::endl;
using std::string;

class Zombie
{
	private:
		string  _name;
	public:
		Zombie();
		Zombie(string name);
		~Zombie();

		void    announce(void);
		void    newZombie(string name);
		void    randomChump();
};    

#endif