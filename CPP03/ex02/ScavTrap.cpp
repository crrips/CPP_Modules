#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->_name = "Scav";
    this->_hit = 100;
    this->_energy = 50;
    this->_attackDamage = 20;
    std::cout << "Default constructor called (ScavTrap)" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor called (ScavTrap)" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    this->_hit = 100;
    this->_energy = 50;
    this->_attackDamage = 20;
    std::cout << "Constructor with parameters called (ScavTrap)" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "Copy constructor called (ScavTrap)" << std::endl;
    (*this) = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "Copy assignment operator called (ScavTrap)" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hit = other._hit;
        this->_energy = other._energy;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if ((int)this->_hit < 1 || (int)this->_energy < 1)
    {
        std::cout << "ScavTrap " << this->_name << " can't do anything" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->_name << " attacks "
    << target << ", causing " << this->_attackDamage << " points of damage!\n";
    this->_energy--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " guard gate activated!" << std::endl;
}
