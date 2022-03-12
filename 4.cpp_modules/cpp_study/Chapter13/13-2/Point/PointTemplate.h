#ifndef POINT_H
#define POINT_H

#include <iostream>

template <typename T>
class Point
{
    private:
        T xpos, ypos;
    public:
        Point(T x=0, T y=0);
        void ShowPosition() const;
};

#endif