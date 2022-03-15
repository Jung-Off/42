#include "mutantstack.hpp"

void iterator_test()
{
    mutantstack<int> mstack;
    mstack.push(1);
    mstack.push(17);

    std::cout << "top : " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size : " << mstack.size() << std::endl;    
    mstack.push(010);
    mstack.push(666);
    mstack.push(777);
    
    mstack.push(0);
    mutantstack<int>::iterator it = mstack.begin();
    mutantstack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
    }
}

void const_iterator_test()
{
    mutantstack<char> mstack;
    mstack.push('a');
    mstack.push('b');
    mstack.push('c');
    mstack.push('d');
    mstack.push('e');

    mutantstack<char>::const_iterator cit = mstack.cbegin();
    mutantstack<char>::const_iterator cite = mstack.cend();
    ++cit;
    --cit;
    while (cit != cite) {
    std::cout << *cit << std::endl;
    ++cit;
    }
}

void reverse_iterator_test()
{
    mutantstack<double> mstack;
    mstack.push(1.0);
    mstack.push(2.2);
    mstack.push(3.3);
    mstack.push(4.4);
    mstack.push(5.5);

    mutantstack<double>::reverse_iterator rit = mstack.rbegin();
    mutantstack<double>::reverse_iterator rite = mstack.rend();
    ++rit;
    --rit;
    while (rit != rite) {
    std::cout << *rit << std::endl;
    ++rit;
    }
}

void reverse_const_iterator_test()
{
    mutantstack<std::string> mstack;
    mstack.push("apple");
    mstack.push("baa");
    mstack.push("sea");
    mstack.push("fineapple");

    mutantstack<std::string>::const_reverse_iterator crit = mstack.crbegin();
    mutantstack<std::string>::const_reverse_iterator crite = mstack.crend();
    ++crit;
    --crit;
    while (crit != crite) {
    std::cout << *crit << std::endl;
    ++crit;
    }
}

int main()
{
    std::cout << "iterator_test" << std::endl;
    iterator_test();
    std::cout << std::endl;

    std::cout << "const_iterator_test" << std::endl;
    const_iterator_test();
    std::cout << std::endl;

    std::cout << "reverse_iterator_test" << std::endl;
    reverse_iterator_test();
    std::cout << std::endl;

    std::cout << "reverse_const_iterator_test" << std::endl;
    reverse_const_iterator_test();
    std::cout << std::endl;

}