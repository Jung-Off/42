
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

template<typename T>
typename T::iterator easyfind(T& container, int data)
{
    typename T::iterator ret = std::find(container.begin(), container.end(), data);
    if (ret == container.end())
        throw(std::exception());
    return (ret);
}

#endif