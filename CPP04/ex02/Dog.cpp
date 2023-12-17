#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Default constructor called (Dog)" << std::endl;
    this->_brain = new Brain();
}

Dog::~Dog()
{
    delete this->_brain;
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
    {
        this->type = other.type;
        this->_brain = other._brain;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}
