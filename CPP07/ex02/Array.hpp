#pragma once

#include <iostream>

template <typename T>
class Array
{
    private:
        T* _array;
    public:
        Array(void) : _array(NULL) {};
        Array(unsigned int n) : _array(new T[n]) {};
        Array(const Array & other) : _array(NULL) { *this = other; };
        ~Array(void) { delete [] _array; };

        
};
