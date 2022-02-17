#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _FixedPoint;
        static const int _bits = 8;  

    public:
        Fixed();
        Fixed(const Fixed& fixed);
        Fixed(const int intger);
        Fixed(const float Float);
        Fixed& operator=(const Fixed& fixed);
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed &f);


#endif