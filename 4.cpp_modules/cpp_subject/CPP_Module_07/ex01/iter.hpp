#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *target, int length, void (*f)(const T&))
{
    for (int i = 0; i < length; i++)
        f(target[i]);
    std::cout << std::endl;
}

template <typename T>
void print(const T& a)
{
    std::cout << a << " ";
}

#endif