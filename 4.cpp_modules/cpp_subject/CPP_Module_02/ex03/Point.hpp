#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed _x;
        const Fixed _y;
    public:
        Point();
        Point(Fixed x, Fixed y);
        ~Point();
        Point(const Point& p);
        Point& operator=(const Point& p);
        Point operator-(const Point& p) const;

        const Fixed getX() const;
        const Fixed getY() const;
};

std::ostream& operator<<(std::ostream& os, const Point& p);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif