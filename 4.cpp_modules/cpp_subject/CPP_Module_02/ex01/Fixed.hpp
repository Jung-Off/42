#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _FixedPoint;
        static const int _bits = 8;
    public:
        Fixed();
        Fixed(const int intger);
        // Fixed(const float Float);
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed& fixed);
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int const raw);
        int toInt(void) const;
};

#endif