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

        bool operator>(const Fixed& f);
        bool operator<(const Fixed& f);
        bool operator>=(const Fixed& f);
        bool operator<=(const Fixed& f);
        bool operator==(const Fixed& f);
        bool operator!=(const Fixed& f);

        Fixed operator+(const Fixed& b);
        Fixed operator-(const Fixed& b);
        Fixed operator*(const Fixed& b);
        Fixed operator/(const Fixed& b);

        Fixed& operator++();        // 전위 증가
        const Fixed operator++(int);   // 후위 증가 //const는 원래도 안되서 똑같이 하기 위함
        Fixed& operator--();        // 전위 감소
        const Fixed operator--(int);    // 후위 감소

        const Fixed& max(const Fixed& a, const Fixed& b);
        const Fixed& min(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream &os, const Fixed &f);


#endif