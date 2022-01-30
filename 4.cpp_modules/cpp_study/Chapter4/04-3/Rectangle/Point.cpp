#include <iostream>
#include "Point.h"
using namespace std;

// bool Point::InitMembers(int xpos, int ypos)
// {
//     if (xpos < 0 || ypos < 0)
//     {
//         cout << "벗어난 범위의 값 전달" << endl;
//         return false;
//     }
//     _x = xpos;
//     _y = ypos;
//     return true;
// }

Point::Point(const int &xpos, const int &ypos)
// Point::Point(int xpos, int ypos)
{
    _x = xpos;
    _y = ypos;
}

int Point::GetX() const //const 함수
{
    return _x;
}

int Point::GetY() const //const 함수
{
    return _y;
}

bool Point::SetX(int xpos)
{
    if (0 > xpos || xpos > 100)
    {
        cout << "벗어난 범위의 값 전달" << endl;
        return false;
    }
    _x = xpos;
    return true;
}

bool Point::SetY(int ypos)
{
    if (0 > ypos || ypos > 100)
    {
        cout << "벗어난 범위의 값 전달" << endl;
        return false;
    }
    _y = ypos;
    return true;
}