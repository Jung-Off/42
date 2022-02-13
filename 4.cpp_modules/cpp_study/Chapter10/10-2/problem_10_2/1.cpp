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
        Point operator-()
        {
            Point ret(-xpos, -ypos);
            return ret;
        }
        friend Point operator~(Point &ref);
};

Point operator~(Point &ref)
{
    Point ret(ref.ypos, ref.xpos);
    return ret;
}

int main()
{
    Point pos(1, 2);


    std::cout << "problem_1" << std::endl;
    Point pos2 = -pos;
    pos.ShowPosition();
    pos2.ShowPosition();

    std::cout << "problem_2" << std::endl;
    Point pos3 = ~pos;
    pos.ShowPosition();
    pos3.ShowPosition();

    return 0;
}

