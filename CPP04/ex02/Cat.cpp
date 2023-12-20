#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Default constructor called (Cat)" << std::endl;
    this->_brain = new Brain();
}

Cat::~Cat()
{
    delete this->_brain;
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
    {
        this->type = other.type;
        this->_brain = new Brain();
        *this->_brain = *other._brain;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
