#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "Default constructor called (WrongCat)" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor called (WrongCat)" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal("WrongCat")
{
    std::cout << "Copy constructor called (WrongCat)" << std::endl;
    (*this) = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "Copy assignment operator called (WrongCat)" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong meow" << std::endl;
}
