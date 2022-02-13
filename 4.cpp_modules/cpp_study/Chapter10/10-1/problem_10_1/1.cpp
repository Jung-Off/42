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
        Point& operator+=(const Point &pos1)
        {
            xpos += pos1.xpos;
            ypos += pos1.ypos;
            return (*this);
        }

        Point& operator-=(const Point &pos1)
        {
            xpos -= pos1.xpos;
            ypos -= pos1.ypos;
            return (*this);
        }
        friend Point operator-(const Point &pos1, const Point &pos2);
        friend bool operator==(const Point &pos1, const Point &pos2);
        friend bool operator!=(const Point &pos1, const Point &pos2);
};

Point operator-(const Point &pos1, const Point &pos2)
{
    Point pos(pos1.xpos-pos2.xpos, pos1.ypos-pos2.ypos);
    return pos;
}

bool operator==(const Point &pos1, const Point &pos2)
{
    if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
        return (true);
    return (false);
}

bool operator!=(const Point &pos1, const Point &pos2)
{
    return (!(pos1 == pos2));
}

int main()
{
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1 - pos2;

    std::cout << "==== problem_1 ====" << std::endl;

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    std::cout << "==== problem_2 ====" << std::endl;
    pos2 += pos1;
    pos1.ShowPosition();
    pos2.ShowPosition();

    std::cout << "==== problem_2_1 ==== " << std::endl;
    pos3 -= pos1;
    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    std::cout << "==== problem_3 ==== " << std::endl;
    Point pos4(1, 3);
    Point pos5(1, 3);
    Point pos6(2, 3);

    if (pos4 == pos5)
        std::cout << "p4, p5 same !" << std::endl;
    else
        std::cout << "p4, p5 different !" << std::endl;

    if (pos4 != pos6)
        std::cout << "p4, p6 different !" << std::endl;
    else
        std::cout << "p4, p6 same !" << std::endl;

    if (pos4 == pos6)
        std::cout << "p4, p6 same !" << std::endl;
    else
        std::cout << "p4, p6 different !" << std::endl;

    if (pos4 != pos5)
        std::cout << "p4, p5 different !" << std::endl;
    else
        std::cout << "p4, p5 same !" << std::endl;


    return 0;
}