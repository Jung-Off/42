#include <iostream>
using namespace std;

class Point
{
    private:
        int xpos, ypos;
    public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    {
        std::cout << "new" << std::endl;
    }
    ~Point()
    {
        std::cout << "delete" << std::endl;
    }
    void ShowPosition() const{
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point (const Point &cpy)
    {
        std::cout << "copy constructor" << std::endl;
    }

    Point operator-()
    {
        // Point
        Point p(-1 * xpos, -1 * ypos);
        return p;

        // Point *new_p = new Point(-1 * xpos, -1 * ypos);
        // printf("hello\n");
        // return (*new_p);
    }

};


int main()
{
    Point pos(1, 2);

    // printf("bbbbbb\n");
    Point minus_pos = -pos;
    //  printf("cccc\n");

    (-pos).ShowPosition();

    pos.ShowPosition();
    // minus_pos.ShowPosition();
    return 0;
}