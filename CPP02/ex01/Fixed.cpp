#include "Fixed.hpp"

Fixed::Fixed()
{
    this->_val = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int i_val)
{
    std::cout << "Int constructor called" << std::endl;
    this->_val = i_val << _bits;
}

Fixed::Fixed(const float f_val)
{
    std::cout << "Float constructor called" << std::endl;
    this->_val = roundf(f_val * (1 << _bits));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (*this) = other;
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
    out << obj.toFloat();
    return out;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_val = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_val;
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->_val = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->_val / (1 << _bits);

}

int Fixed::toInt(void) const
{
    return this->_val >> _bits;
}
