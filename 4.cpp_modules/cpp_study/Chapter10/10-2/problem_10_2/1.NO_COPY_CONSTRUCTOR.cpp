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
    // Point (const Point &cpy)
    // {
    //     std::cout << "copy constructor" << std::endl;
    // }

    Point operator-()
    {
        Point p(-1 * xpos, -1 * ypos);
        return p;
    }

};


int main()
{
    Point pos(1, 2);
    Point minus_pos = -pos;
    std::cout << "------------------------" << '\n';
    (-pos).ShowPosition();
    std::cout << "------------------------" << '\n';
    
    minus_pos.ShowPosition();
    pos.ShowPosition();
    std::cout << "------------------------" << '\n';
    (-pos).ShowPosition();
    std::cout << "------------------------" << '\n';

    return 0;
}