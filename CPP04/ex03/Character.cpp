#include "Character.hpp"

Character::Character()
{
    this->_name = "default";
    this->_inventory = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

Character::Character(std::string const &name)
{
    this->_name = name;
    this->_inventory = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete this->_inventory[i];
    delete [] this->_inventory;
}

Character::Character(const Character &other)
{
    this->_name = other._name;
    this->_inventory = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = other._inventory[i]->clone();
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        for (int i = 0; i < 4; i++)
            delete this->_inventory[i];
        delete [] this->_inventory;
        this->_inventory = new AMateria*[4];
        for (int i = 0; i < 4; i++)
            this->_inventory[i] = other._inventory[i]->clone();
    }
    return *this;
}

std::string const &Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
        this->_inventory[idx]->use(target);
}
