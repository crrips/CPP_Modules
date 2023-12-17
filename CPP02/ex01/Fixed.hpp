#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _val;
        static const int _bits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &other);
        Fixed(const int i_val);
        Fixed(const float f_val);
        Fixed &operator=(const Fixed &other);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif