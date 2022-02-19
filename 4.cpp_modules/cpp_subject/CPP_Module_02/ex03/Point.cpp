#include "Point.hpp"

Point::Point()
    :   _x(0), _y(0)
    {}

Point::Point(Fixed x, Fixed y)
    :   _x(x), _y(y)
    {}

Point::~Point()
    {}

//copy도 이니셜라이저 가능!
Point::Point(const Point& p)
    : _x(p.getX()), _y(p.getY())
    {}

Point& Point::operator=(const Point& p)
{
    if(this != &p)
    {
        (Fixed&)_x = p.getX();
        (Fixed&)_y = p.getY();
    }
    return (*this);
}

const Fixed Point::getX() const
{
    return (_x);
}

const Fixed Point::getY() const
{
    return (_y);
}

//객체에 const선언 const함수 호출만 허용!
Point Point::operator-(const Point& p) const
{
    Point res(getX().toFloat() - p.getX().toFloat(), getY().toFloat() - p.getY().toFloat());

    return (res);
}
 
std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "[" << p.getX().toFloat() << ", " << p.getY().toFloat() << "]" << std::endl;
    return (os);
}

