#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->_name = "Frag";
    this->_hit = 100;
    this->_energy = 100;
    this->_attackDamage = 30;
    std::cout << "Default constructor called (FragTrap)" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor called (FragTrap)" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    this->_hit = 100;
    this->_energy = 10;
    this->_attackDamage = 30;
    std::cout << "Constructor with parameters called (FragTrap)" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "Copy constructor called (FragTrap)" << std::endl;
    (*this) = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "Copy assignment operator called (FragTrap)" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hit = other._hit;
        this->_energy = other._energy;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

void FragTrap::attack(const std::string &target)
{
    if ((int)this->_hit < 1 || (int)this->_energy < 1)
    {
        std::cout << "FragTrap " << this->_name << " can't do anything" << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->_name << " attacks "
    << target << ", causing " << this->_attackDamage << " points of damage!\n";
    this->_energy--;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << " called high five guys" << std::endl;
}
