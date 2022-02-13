#include <iostream>

using namespace std;

class Point {
    private:
        int x, y;
    public:
    Point (int x = 0, int y = 0) : x(x), y(y)
    {}
    void ShowPosition() const{
            cout << '[' << x << ", " << y << ']' << endl;
        }
    friend istream& operator>>(istream& os, Point& ps);
    friend ostream& operator<<(ostream& os, const Point& ps);

};

istream& operator>>(istream& is, Point& ps)
{
    is >> ps.x >> ps.y;
    return is;
}

ostream& operator<<(ostream& os, const Point& ps)
{
    os << '[' << ps.x << ", " << ps.y << ']' << endl;
    return os;
}

int main()
{
    Point pos1;
    cout << "x, y 좌표 순으로 입력: " << std::endl;
    cin >> pos1;
    cout << pos1;

    Point pos2;
    cout << "x, y 좌표 순으로 입력: " << std::endl;
    cin >> pos2;
    cout << pos2;
}