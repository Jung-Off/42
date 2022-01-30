#include <iostream>
using namespace std;

class Point
{
    private:
        int _xpos;
        int _ypos;
    public:
        void Init(int x, int y)
        {
            _xpos = x;
            _ypos = y;
        }
        void ShowPointInfo() const
        {
            cout << "[" << _xpos << ", " << _ypos << "]" << endl;
        }
};

class Circle
{
    private:
        Point   _cen;
        int     _r;
    public:
        void Init(int x, int y, int r)
        {
            _cen.Init(x, y);
            _r = r;
        }
        void ShowCircle() const
        {
            cout << "radius : " << _r << endl;
            _cen.ShowPointInfo();
        }
};

class Ring
{
    private:
        Circle  _inner;
        Circle  _outer;
    public:
        void Init(int in_x, int in_y, int in_r, int x, int y, int r)
        {
            _inner.Init(in_x, in_y, in_r);
            _outer.Init(x, y, r);
        }
        void ShowRingInfo() const
        {
            cout << "Inner Circle Info..." << endl;
            _inner.ShowCircle();
            cout << "Outer Circle Info..." << endl;
            _outer.ShowCircle();
        }
};

int main()
{
    Ring ring;
    ring.Init(1,1,4,2,2,9);
    ring.ShowRingInfo();
    return 0;
}