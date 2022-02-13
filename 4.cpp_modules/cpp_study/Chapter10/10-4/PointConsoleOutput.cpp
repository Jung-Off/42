#include <iostream>

using namespace std;

class Point
{
    private:
        int xpos, ypos;
    public:
        Point (int x = 0, int y = 0) : xpos(x), ypos(y)
        {}
        void ShowPosition() const{
            cout << '[' << xpos << ", " << ypos << ']' << endl;
        }
        friend ostream& operator<<(ostream& os, const Point& pos);
};

// ostream 객체 내부에 멤버함수를 추가해야되는데 ostream 클래스를 수정하는것은 불가능! 
// 전역함수로 정의!
ostream& operator<<(ostream& os, const Point& pos)
{
    os << '[' << pos.xpos << ", " <<pos.ypos << ']' << endl;
    return os;
}

int main()
{
    Point pos1(1, 3);
    cout << pos1;
    Point pos2(101, 303);
    cout << pos2;
    return 0;
}