
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
    
    // std::cout << Fixed::min( a, b ) << std::endl;
    // std::cout << (a > b) << std::endl;  //0
    // std::cout << (a < b) << std::endl;  //1
    // std::cout << (a >= b) << std::endl; //0
    // std::cout << (a <= b) << std::endl; //1
    // std::cout << (a == b) << std::endl; //0
    // std::cout << (a != b) << std::endl; //1
    
    // Fixed c(42.42f);
    // Fixed d(3);
    // std::cout << "c : " << c << std::endl;
    // std::cout << (float)(c.getRawBits()) / 256 << std::endl;    //42.4219
    // std::cout << c.getRawBits() << std::endl;           //10860
    // std::cout << "c + d : " << c + d << std::endl;    //45.4219
    // std::cout << "c - d : " << c - d << std::endl;    //39.4219
    // std::cout << "c * d : " << c * d << std::endl;    //127.266
    // std::cout << "c / d : " << c / d << std::endl;    //14.1406

    return 0;
}