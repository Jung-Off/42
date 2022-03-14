#include "span.hpp"

int main()
{
    span testSpan(10000);

    std::vector<int>::iterator begin;
    begin = testSpan.getData().begin();
    std::vector<int>::iterator end = begin + 10000;
    testSpan.addNumber(begin, end);

    try
    {
        std::cout << "overflow test ! ! !" << std::endl;
        testSpan.addNumber(10);
        std::cout << "overflow test ! ! !" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // std::cout << testSpan.shortestSpan() << std::endl; //제일 짧은 span은 1
    // std::cout << testSpan.longestSpan() << std::endl;

    std::cout << std::endl;

    span s(6);
    // s.addNumber(5);
    try
    {
        //0개 일때 span구하기
        std::cout << s.shortestSpan() << std::endl; //제일 짧은 span은 2 5 // 3
        std::cout << s.longestSpan() << std::endl;  //제일 긴 span은 -9 26 // 35
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;
    try
    {
        s.addNumber(5);
        s.addNumber(-9);
        s.addNumber(10);
        s.addNumber(26);
        s.addNumber(-4);
        s.addNumber(2);
        std::cout << "overflow test ! ! !" << std::endl;
        s.addNumber(0);
        std::cout << "overflow test ! ! !" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << s.shortestSpan() << std::endl; //제일 짧은 span은 2 5 // 3
    std::cout << s.longestSpan() << std::endl;  //제일 긴 span은 -9 26 // 35

    //private -> public 으로 변화해서 아래 찍으면
    // span s1(s);
    // int *vec_address = &s._data[0];
    // int *copyvec_address = &s1._data[0];

    // std::cout << "copy_vec : " << copyvec_address << std::endl;
    // std::cout << "vec: " << vec_address << std::endl;

    // span s2;
    // s2 = s;
    // int *vec_address2 = &s._data[0];
    // int *copyvec_address2 = &s2._data[0];
    // std::cout << "copy_vec : " << copyvec_address2 << std::endl;
    // std::cout << "vec: " << vec_address2 << std::endl;
}

    // std::vector<int> vec;
    // vec.push_back(5);
    // vec.push_back(3);
    // vec.push_back(2);
    // vec.push_back(17);
    // vec.push_back(1);
    // std::vector<int> copy_vec(vec);

    // int *vec_address = &vec[0];
    // int *copyvec_address = &copy_vec[0];

    // std::cout << "copy_vec : " << copyvec_address << std::endl;
    // std::cout << "vec: " << vec_address << std::endl;
