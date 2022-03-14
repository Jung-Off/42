#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#define INF 100000

class span
{
    private:
        unsigned int        _size;
        std::vector<int>    _data;
    public:
        span();
        span(unsigned int n);
        span(const span& s);
        span& operator=(const span& s);
        ~span();        

        void addNumber(int newN);
        void addNumber(std::vector<int>::iterator s, std::vector<int>::iterator e);

        int shortestSpan() const;
        int longestSpan() const;
        
        class OverFlowException : public std::exception
        {
            const char * what() const throw();
        };

        class EmptyException : public std::exception
        {
            const char * what() const throw();
        };

        unsigned int getSize() const;
        std::vector<int> getData() const;
};

#endif