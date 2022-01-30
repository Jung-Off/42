#include <iostream>
#include "Rectangle.h"
using namespace std;

// bool Rectangle::InitMembers(const Point &ul, const Point &lr)
// {
//     if(ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
//     {
//         cout << "잘못된 위치정보 정달" << endl;
//         return false;
//     }
//     _upLeft = ul;
//     _lowRight = lr;
//     return true;
// }

//

Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2)
    : _upLeft(x1, y1), _lowRight(x2, y2)
    //객체를 초기화 하기위해 Point객체의 생성자 불러오기!
{

}
void Rectangle::ShowRecInfo() const
{
    cout << "좌 상단 : " << '[' << _upLeft.GetX() << ", ";
    cout << _upLeft.GetY() << ']' << endl;
    cout << "우 하단 : " << '[' << _lowRight.GetX() << ", ";
    cout << _lowRight.GetY() << ']' << endl;
}