#include "Scalar.hpp"

Scalar::Scalar()
    {}

Scalar::Scalar(const Scalar& s)
    : _input(s.getInput()), _type(s._type)
    {}

Scalar& Scalar::operator=(const Scalar& s)
{
    if (this != &s)
    {
        _type = s.getType();
        _input = getInput();
    }   
    return (*this);
}

Scalar::~Scalar()
    {}

std::string Scalar::getInput() const
{
    return (_input);
}

int Scalar::getType() const
{
    return (_type);
}

Scalar::Scalar(const std::string s)
    : _input(s)
{
    _type = N;
    if (_input.length() == 1 && !isdigit(_input.at(0)))
        _type = C;
}

int Scalar::toInt() const
{
    int ret;
    if (_type == C)
        ret =  static_cast<int>(_input.at(0));
    else
    {
        try
        {
            ret = std::stoi(_input);
        }
        catch(const std::exception& e)
        {
            //문자열, 최대, 최소
            throw (ImpossibleException());
        }
    }
    return (ret);
}

char Scalar::toChar() const
{
    char ret;
    if (_type == C)
    {
        try
        {
            if (_input.at(0) < 32 || _input.at(0) > 126) //printable char range is 32 ~ 126
                throw NonDisplayException();
            ret = _input.at(0);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
    else
    {
        try
        {
            ret = static_cast<char>(std::stoi(_input));
        }
        catch(const std::exception& e)
        {
            //문자열
            throw (ImpossibleException());
        }
        // 범위 넘어가는 것들
        if (ret < 32 || ret > 126)
        {
            throw (NonDisplayException());
        }
    }
    return (ret);
}

float Scalar::toFloat() const
{
    float ret;
    if (_type == C)
        ret = static_cast<float>(_input.at(0));
    else
    {
        try
        {
            ret = std::stof(_input);
        }
        catch(const std::exception& e)
        {
            //문자열
            throw (ImpossibleException());
        }
    }
    return (ret);
}

double Scalar::toDouble() const
{
    double ret;
    if (_type == C)
        ret = static_cast<double>(_input.at(0));
    else
    {
        try
        {
            ret = static_cast<double>(std::stof(_input));
        }
        catch(const std::exception& e)
        {
            //문자열
            throw (ImpossibleException());
        }
    }
    return (ret);
}

const char * Scalar::NonDisplayException::what() const throw()
{
    return ("Non displayable");
}

const char * Scalar::ImpossibleException::what() const throw()
{
    return ("Impossible");
}

std::ostream &operator<<(std::ostream &os, Scalar const &s)
{
    try
    {
        os << "char : " << s.toChar() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        os << "int : " << s.toInt() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        os << "float : " << s.toFloat();
        if (s.toFloat() - static_cast<int>(s.toFloat()) == 0)
            os << ".0";
        os << "f" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        os << "double : " << s.toDouble();
        if (s.toDouble() - static_cast<int>(s.toDouble()) == 0)
            os << ".0";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return os;
}