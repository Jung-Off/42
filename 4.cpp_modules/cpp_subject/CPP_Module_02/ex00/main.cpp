
#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;    //constructor
    Fixed b(a); //copy
    Fixed c;    //constructor

    c = b;  // =

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}