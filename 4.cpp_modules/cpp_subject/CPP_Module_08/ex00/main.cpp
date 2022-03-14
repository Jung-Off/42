
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(17);
    vec.push_back(1);

    std::vector<int>::iterator vec_iter;

    std::cout << "==== vec_iter =====" << std::endl;
    for (vec_iter = vec.begin(); vec_iter != vec.end(); vec_iter++)
    {
        std::cout << *vec_iter << std::endl;
    }
    std::cout << "==== vec_iter =====" << std::endl;
    try
    {
        vec_iter = easyfind(vec, 1);
        std::cout << "[" << *vec_iter << "]" << std::endl;

        vec_iter = easyfind(vec, 4);
        std::cout << "[" << *vec_iter << "]" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(3);
    lst.push_back(2);
    lst.push_back(17);
    lst.push_back(1);
    
    std::list<int>::iterator lst_iter;
    std::cout << "==== lst_iter =====" << std::endl;
    for (lst_iter = lst.begin(); lst_iter != lst.end(); lst_iter++)
    {
        std::cout << *lst_iter << std::endl;
    }
    std::cout << "==== lst_iter =====" << std::endl;
    try
    {
        lst_iter = easyfind(lst, 1);
        std::cout << "[" << *lst_iter << "]" << std::endl;

        lst_iter = easyfind(lst, 4);
        std::cout << "[" << *lst_iter << "]" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


}