#pragma once

#include <iostream>

template <typename T>
class Array
{
    private:
        T * _array;
        unsigned int _size;
        class OutOfBounds : public std::exception
        {
            virtual const char * what() const throw() { return "Out of bounds"; };
        };
    public:
        Array(void) : _array(NULL), _size(0) {};
        Array(unsigned int n) : _array(new T[n]), _size(n) {};
        Array(const Array & other) : _array(NULL), _size(0) { *this = other; };
        ~Array(void) { delete [] _array; };

        Array & operator=(const Array & other)
        {
            if (this != &other)
            {
                delete [] _array;
                _array = new T[other._size];
                _size = other._size;
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = other._array[i];
            }
            return *this;
        };

        T & operator[](unsigned int i)
        {
            if (i >= _size)
                throw OutOfBounds();
            return _array[i];
        };

        const T & operator[](unsigned int i) const
        {
            if (i >= _size)
                throw OutOfBounds();
            return _array[i];
        };

        unsigned int size(void) const { return _size; };
};
