#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->_name = "Clap";
    this->_hit = 10;
    this->_energy = 10;
    this->_attackDamage = 0;
    std::cout << "Default constructor called (ClapTrap)" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called (ClapTrap)" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->_name = name;
    this->_hit = 10;
    this->_energy = 10;
    this->_attackDamage = 0;
    std::cout << "Constructor with parameters called (ClapTrap)" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called (ClapTrap)" << std::endl;
    (*this) = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assignment operator called (ClapTrap)" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hit = other._hit;
        this->_energy = other._energy;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
    if ((int)this->_hit < 1 || (int)this->_energy < 1)
    {
        std::cout << "ClapTrap " << this->_name << " can't do anything" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " attacks "
    << target << ", causing " << this->_attackDamage << " points of damage!\n";
    this->_energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << this->_name << " takes " << amount << " damage\n";
    this->_hit -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if ((int)this->_hit < 1 || (int)this->_energy < 1)
    {
        std::cout << this->_name << " can't do anything" << std::endl;
        return;
    }
    std::cout << this->_name << " repairs and gets " << amount << " points\n";
    this->_hit += amount;
    this->_energy--;
}

std::string ClapTrap::getName(void)
{
    return this->_name;
}
