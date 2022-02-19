
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
    //a
    Point ap = p - a;
    Point ab = b - a;
    //b
    Point bp = p - b;
    Point bc = c - b;
    //c
    Point cp = p - c;
    Point ca = a - c;

    //vector calculate
    float apab = (ap.getX().toFloat() * ab.getY().toFloat()) - (ap.getY().toFloat() * ab.getX().toFloat());
    float bpbc = (bp.getX().toFloat() * bc.getY().toFloat()) - (bp.getY().toFloat() * bc.getX().toFloat());
    float cpca = (cp.getX().toFloat() * ca.getY().toFloat()) - (cp.getY().toFloat() * ca.getX().toFloat());

    std::cout << "[" << apab << ", " << bpbc << ", " << cpca << "]" << std::endl;
    if (apab >= 0 || bpbc >= 0 || cpca >= 0)
        return (false);
    return (true);
}