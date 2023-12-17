#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Default constructor called (Animal)" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Destructor called (Animal)" << std::endl;
}

Animal::Animal(const std::string name)
{
    this->type = name;
    std::cout << "Constructor with parameters called (Animal)" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Copy constructor called (Animal)" << std::endl;
    (*this) = other;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Copy assignment operator called (Animal)" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}
