#include <iostream>

class Rectangle
{
    private:
        int x;
        int y;
    public:
        Rectangle(int x, int y)
            :   x(x), y(y)
        {}
        void ShowAreaInfo()
        {
            std::cout << "면적 : " << x * y << std::endl;
        }
};

class Square : public Rectangle
{
    public:
        Square(int n)
            :   Rectangle(n, n)
        {}
};

int main()
{
    Rectangle rec(4,3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}