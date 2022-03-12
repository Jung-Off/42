#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T*              _data;
        unsigned int    _size;
    public:
        Array() :   _data(NULL), _size(0) {}
        Array(unsigned int n) : _size(n) { _data = new T[n]; }
        Array(const Array& a) : _size(a.size())
        {
            _data = NULL;
            if (_size)
            {
                _data = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _data[i] = a[i];
            }
        }
        Array& operator=(const Array& a)
        {
            if (this != &a)
            {
                if (_data != NULL)
                    delete[] _data;
                _size = a.size();
                if (_size)
                    _data = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _data[i] = a[i];
            }
            return (*this);
        }
        T& operator[](unsigned int idx)
        {
            if (idx >= _size)
                throw (InaccessibleException());
            return _data[idx];
        }
        ~Array()    { delete[] _data; }

        class InaccessibleException : public std::exception
        {
            const char * what() const throw()
            {
                return ("Inaccessible Idx");
            }
        };

        unsigned int size() const { return (_size); }
};

#endif