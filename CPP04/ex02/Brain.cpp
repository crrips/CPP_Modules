#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default constructor called (Brain)" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Destructor called (Brain)" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Copy constructor called (Brain)" << std::endl;
    (*this) = other;
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Copy assignment operator called (Brain)" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    return *this;
}
