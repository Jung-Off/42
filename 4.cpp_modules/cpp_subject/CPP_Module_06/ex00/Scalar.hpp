#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <string>
#include <cmath>

class Scalar
{
    private:
        std::string _input;
        int         _type;
        double      _num;
    public:
        enum { C, N };
        Scalar();
        Scalar(const Scalar& s);
        Scalar& operator=(const Scalar& s);
        ~Scalar();

        Scalar(const std::string s);
        std::string getInput() const;
        double getNum() const;

        class NonDisplayException : public std::exception
        {
            const char * what() const throw();
        };

        class ImpossibleException : public std::exception
        {
            const char * what() const throw();
        };

        int toInt() const;
        char toChar() const;
        float toFloat() const;
        double toDouble() const;

};

std::ostream &operator<<(std::ostream &os, Scalar const &s);


#endif