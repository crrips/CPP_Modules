#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
    private:
        unsigned int _size;
        std::vector<int> _numbers;
    public:
        Span();
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        Span(unsigned int n);

        void addNumber(int n);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
};
