#include <iostream>
using namespace std;

class Point
{
    private:
        int xpos, ypos;
    public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    {
        std::cout << "Constructor" << std::endl;
    }
    ~Point()
    {
        std::cout << "Destructor" << std::endl;
    }
    void ShowPosition() const{
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point (const Point &cpy)
    {
        xpos = cpy.xpos;
        ypos = cpy.ypos;
        std::cout << "copy constructor" << std::endl;
    }

    // Point (Point &cpy)
    // {
    //     xpos = cpy.xpos;
    //     ypos = cpy.ypos;
    //     std::cout << "copy constructor" << std::endl;
    // }

    const Point operator-()
    {
        Point p(xpos * -1, ypos * -1);
        return (p);
    }
    friend Point operator~(Point &ref);
};

Point operator~(Point &ref)
{
    Point ret(ref.ypos, ref.xpos);
    return (ret);
}

int main()
{
    Point p(1,2);
    p.ShowPosition();
    Point minus_p = -p;

    std::cout << "minus_p" << std::endl << std::endl;
    minus_p.ShowPosition();
    std::cout << "p" << std::endl << std::endl;
    p.ShowPosition();

    std::cout << "====================" << std::endl;
    
    Point pos2 = ~p;
    std::cout << "p" << std::endl;
    p.ShowPosition();
    std::cout << "pos2" << std::endl;
    pos2.ShowPosition();

    return 0;
}