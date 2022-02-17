#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _FixedPoint;
        static const int _bits = 8;  
        //static const 는 이런식으로 초기화를 한다고 합니다
        
        //const int는 생성자 이니셜라이저에서
        
        //static는 객체 내부의 메모리가 아니니까
        //class 외부에서 int Fixed::bits = 8;
    public:
        Fixed();
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed& fixed);
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int const raw);
};

#endif