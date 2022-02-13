#include <iostream>
using namespace std;

class Point
{
    private:
        int xpos, ypos;
    public:
        Point(int x = 0, int y = 0) : xpos(x), ypos(y)
        { }
        void ShowPosition() const
        {
            cout << '[' << xpos << ", " << ypos << ']' << endl;
        }
        Point& operator++() //전위 증가
        {
            xpos+=1;
            ypos+=1;
            return (*this);
        }
        const Point operator++(int)
        {
            const Point ret(xpos, ypos);
            xpos += 1;
            ypos += 1;
            return(ret);
        }
        friend Point& operator--(Point &ref);
        friend const Point operator--(Point &ref, int);
};

Point& operator--(Point &ref)
{
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

const Point operator--(Point &ref, int)
{
    Point ret(ref.xpos, ref.ypos);
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ret;
}

int main()
{
    Point pos(3, 5);
    Point cpy;
    cpy = pos--;
    cpy.ShowPosition();
    pos.ShowPosition();

    cpy=pos++;
    cpy.ShowPosition();
    pos.ShowPosition();
    return 0;
}

