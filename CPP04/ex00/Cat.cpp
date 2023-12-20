#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Default constructor called (Cat)" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Destructor called (Cat)" << std::endl;
}

Cat::Cat(const Cat &other) : Animal("Cat")
{
    std::cout << "Copy constructor called (Cat)" << std::endl;
    (*this) = other;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Copy assignment operator called (Cat)" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
