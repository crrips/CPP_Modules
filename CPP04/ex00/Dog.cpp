#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Default constructor called (Dog)" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Destructor called (Dog)" << std::endl;
}

Dog::Dog(const Dog &other) : Animal("Dog")
{
    std::cout << "Copy constructor called (Dog)" << std::endl;
    (*this) = other;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Copy assignment operator called (Dog)" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}
