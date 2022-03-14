#include "span.hpp"

span::span() : _size(0), _data(0)
    {}

span::span(unsigned int n) : _size(n), _data(0)
    {}

span::span(const span& s) : _size(s.getSize()), _data(s.getData())
    {}

span& span::operator=(const span& s)
{
    if (this != &s)
    {
        _size = s.getSize();
        _data = s.getData();    
        //deep copy인지 확인 private으로 고쳐야 확인 가능
        //벡터끼리 복사 할 땐 대입 연산자 쓰면 됨! 자동으로 리사이즈 + 깊은 복사!
    }
    return (*this);
}

span::~span()
    {}

void span::addNumber(int newN)
{
    if (_data.size() >= _size)
        throw(OverFlowException());
    _data.push_back(newN);
}

void span::addNumber(std::vector<int>::iterator s, std::vector<int>::iterator e)
{
    std::vector<int>::iterator iter;
    int i = 1;

    for (iter = s; iter != e; iter++)
    {
        addNumber(i);
        i++;
    }
}

int span::shortestSpan() const
{
    if (_data.size() <= 1)
        throw (EmptyException());
    std::vector<int>    copy = _data;
    std::vector<int>::iterator copy_itr;    
    std::sort(copy.begin(), copy.end());
    int min = INF;
    int temp = 0;
    for (copy_itr = copy.begin(); copy_itr != copy.end() - 1; copy_itr++)
    {
        temp = *(copy_itr + 1) - *copy_itr;
        min = (min > temp ? temp : min);
    }
    return (min);
}

int span::longestSpan() const
{
    if (_data.size() <= 1)
        throw (EmptyException());
    int min = *std::min_element(_data.begin(), _data.end());
    int max = *std::max_element(_data.begin(), _data.end());

    return (max - min);
}

const char * span::OverFlowException::what() const throw()
{
    return ("overFlow");
}

const char * span::EmptyException::what() const throw()
{
    return ("Empty");
}

unsigned int span::getSize() const
{
    return (_size);
}

std::vector<int> span::getData() const
{
    return (_data);
}