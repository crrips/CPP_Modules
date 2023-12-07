#include "Fixed.hpp"

Fixed::Fixed()
{
    this->_val = 0;
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int i_val)
{
    // std::cout << "Int constructor called" << std::endl;
    this->_val = i_val << _bits;
}

Fixed::Fixed(const float f_val)
{
    // std::cout << "Float constructor called" << std::endl;
    this->_val = roundf(f_val * (1 << _bits));
}

Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called" << std::endl;
    (*this) = other;
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
    out << obj.toFloat();
    return out;
}

Fixed &Fixed::operator++(void)
{
    this->_val = this->getRawBits() + 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed ret(*this);

    this->_val = this->getRawBits() + 1;
    return ret;
}

Fixed &Fixed::operator--(void)
{
    this->_val = this->getRawBits() - 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed ret(*this);

    this->_val = this->getRawBits() - 1;
    return ret;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->_val = other.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->toFloat() > other.toFloat();
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->toFloat() < other.toFloat();
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->toFloat() >= other.toFloat();
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->toFloat() <= other.toFloat();
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->toFloat() != other.toFloat();
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed ret(*this);

    ret._val *= other.getRawBits() >> this->_bits;
    return ret;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed ret(*this);

    if (other.getRawBits() != 0)
        ret._val /= other.getRawBits() >> this->_bits;
    else
        std::cout << "error: division by 0. returned divisble number" << std::endl;
    return ret;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed ret(*this);

    ret._val += other.getRawBits() >> this->_bits;
    return ret;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed ret(*this);

    ret._val -= other.getRawBits() >> this->_bits;
    return ret;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;`
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

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
    if (f1 < f2)
        return (f1);
    return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
    if (f1 < f2)
        return (f1);
    return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
    if (f1 > f2)
        return (f1);
    return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
    if (f1 > f2)
        return (f1);
    return (f2);
}
