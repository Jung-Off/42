#include <iostream>
using namespace std;

class Point
{
    public:
        int x;  //0 <= x <= 100
        int y; //0 <= y <= 100
};

class Rectangle
{
    public:
        Point upLeft;
        Point lowRight;

    public:
        void ShowRecInfo()
        {
            cout << "좌 상단 : " << '[' << upLeft.x << ", ";
            cout << upLeft.y << ']' << endl;
            cout << "우 하단 : " << '[' << lowRight.x << ", ";
            cout << lowRight.y << ']' << endl;
        }
};

int main()
{
    Point pos1 = {-2, 4};
    Point pos2 = {5, 9};
    Rectangle rec = {pos2, pos1};
    rec.ShowRecInfo();
    return 0;
}