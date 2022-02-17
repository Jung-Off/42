
#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << Fixed::min(a, b) << std::endl; //0.0078125
    std::cout << std::endl;
    std::cout << --a << std::endl; //0.00390625
    std::cout << a << std::endl; //0.00390625
    std::cout << a-- << std::endl; //0.00390625
    std::cout << a << std::endl; //0
    std::cout << std::endl;
    std::cout << (a > b) << std::endl; // 0
    std::cout << (a < b) << std::endl; //1
    std::cout << (a <= b) << std::endl; //1
    std::cout << (a >= b) << std::endl; //0
    std::cout << (a == b) << std::endl; //0
    std::cout << (a != b) << std::endl; //1
    std::cout << std::endl;
    Fixed plus = a + b;
    std::cout << plus << std::endl; //10.1016
    std::cout << a - b << std::endl; //-10.1016
    std::cout << a * b << std::endl; //0
    std::cout << a / b << std::endl; //0
    std::cout << std::endl;

    return(0);
}