
#include "Point.hpp"

int main( void ) 
{
    Point a(6, 7);
    Point b(3, 2);
    Point c(11, 5);
    Point in(7, 5);
    // Point in(4, 3);  //other in
    Point out(12, 8);   //  out
    // Point out(11, 5);   //  out
    // Point out(7, 3.5f);  //  line
    // Point out(4.5f, 4.5f);   //line

    if(bsp(a,b,c, in))
    {
        std::cout << "this is IN!!!" << std::endl;
        std::cout << "in : " << in << std::endl;
    }
    else
        std::cout << "out : " << in << std::endl;

    if(bsp(a,b,c, out))
    {
        std::cout << "this is IN!!!" << std::endl;
        std::cout << "in : " << out << std::endl;
    }
    else
        std::cout << "out : " << out << std::endl;

    return 0;
}