#include <iostream>
using namespace std;

class Point
{
    private:
        int xpos, ypos;
    public:
        Point(int x = 0, int y = 0) : xpos(x), ypos(y)
        { }
    void ShowPosition() const{
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point(const Point& cpy)
    {
        std::cout << "I am copy" << std::endl;
    }

    Point& operator+=(const Point& pos1)
    {
        xpos += pos1.xpos;
        ypos += pos1.ypos;
        return (*this);
    }

    Point& operator-=(const Point& pos1)
    {
        xpos -= pos1.xpos;
        ypos -= pos1.ypos;
        return (*this);
    }
    friend Point operator-(const Point& pos1, const Point& pos2); //전역함수로 오버로딩
    friend bool operator==(const Point& pos1, const Point& pos2); //전역함수로 오버로딩
    friend bool operator!=(const Point& pos1, const Point& pos2); //전역함수로 오버로딩
};

Point operator-(const Point& pos1, const Point& pos2)
{
    Point ret(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
    return (ret);
}

bool operator==(const Point& pos1, const Point& pos2)
{
    if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
        return (true);
    return (false);
}

bool operator!=(const Point& pos1, const Point& pos2)
{
    // if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
    //     return (false);
    // return (true);
    return (!(pos1==pos2));
}

int main()
{
    {
        Point a(1, 2);
        Point b(3, 4);
        a.ShowPosition();
        b.ShowPosition();
        std::cout << std::endl;

        std::cout << "problem 1 (1)" << std::endl;

        Point c = a - b;
        std::cout << "c = a - b" << std::endl;
        (a - b).ShowPosition();
        // c.ShowPosition();

        std::cout << std::endl;

        std::cout << "problem 1 (2)" << std::endl;
        std::cout << "e = a.operator-(a, b)" << std::endl;
        Point e = operator-(a, b);
        // e.ShowPosition();
        operator-(a, b).ShowPosition();

        std::cout << std::endl;
        std::cout << "problem 1 end" << std::endl;

        std::cout << std::endl << std::endl;
    }    
    std::cout << "problem 2" << std::endl;

    {
        Point a(1, 2);
        Point b(3, 4);
        
        std::cout << "a += b" << std::endl;
        a.ShowPosition();
        b.ShowPosition();
        std::cout << std::endl;
        (a += b).ShowPosition();
        a.ShowPosition();
        std::cout << std::endl;

        Point c(1, 2);
        Point d(3, 4);
        std::cout << "c -= d" << std::endl;
        c.ShowPosition();
        d.ShowPosition();
        std::cout << std::endl;
        (c -= d).ShowPosition();
        c.ShowPosition();
        std::cout << std::endl;
    }

    std::cout << "problem 3" << std::endl;
    std::cout << std::endl;
    {
        Point a(1, 2);
        Point c(1, 2);
        Point b(3, 4);
        Point d(3, 5);
        Point f(4, 4);

    std::cout << "==============" << std::endl;

        std::cout << "[a] [c]" << std::endl;
        if (a == c)
            std::cout << "correct" << std::endl;
        else
            std::cout << " not correct " << std::endl;
        std::cout << std::endl;

        std::cout << "[a] [b]" << std::endl;
        if (a == b)
            std::cout << "correct" << std::endl;
        else
            std::cout << " not correct " << std::endl;
        std::cout << std::endl;

        std::cout << "[b] [d]" << std::endl;        
        if (b == d)
            std::cout << "correct" << std::endl;
        else
            std::cout << " not correct " << std::endl;
        std::cout << std::endl;

        std::cout << "[b] [f]" << std::endl;
        if (b == f)
            std::cout << "correct" << std::endl;
        else
            std::cout << " not correct " << std::endl;
        std::cout << std::endl;

    std::cout << "=!=!=!=!=!=!=!=!=!=!=!=!=!=" << std::endl << std::endl;


        std::cout << "[a] [c]" << std::endl;
        if (a != c)
            std::cout << " not correct" << std::endl;
        else
            std::cout << "  correct " << std::endl;
        std::cout << std::endl;

        std::cout << "[a] [b]" << std::endl;
        if (a != b)
            std::cout << " not correct" << std::endl;
        else
            std::cout << "  correct " << std::endl;
        std::cout << std::endl;

        std::cout << "[b] [d]" << std::endl;        
        if (b != d)
            std::cout << "not correct" << std::endl;
        else
            std::cout << "  correct " << std::endl;
        std::cout << std::endl;

        std::cout << "[b] [f]" << std::endl;
        if (b != f)
            std::cout << "not correct" << std::endl;
        else
            std::cout << "  correct " << std::endl;
        std::cout << std::endl;
    
    }



    return 0;
}

