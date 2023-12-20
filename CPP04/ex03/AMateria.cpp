#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(std::string const &type)
{
    this->_type = type;
}

AMateria::AMateria(const AMateria &other)
{
    this->_type = other._type;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

std::string const &AMateria::getType() const
{
    return this->_type;
}
