#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "Default constructor called (WrongAnimal)" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor called (WrongAnimal)" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string name)
{
    this->type = name;
    std::cout << "Constructor with parameters called (WrongAnimal)" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "Copy constructor called (WrongAnimal)" << std::endl;
    (*this) = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "Copy assignment operator called (WrongAnimal)" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}
