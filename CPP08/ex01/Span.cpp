#include "Span.hpp"

Span::Span() {}

Span::~Span() {}

Span::Span(const Span &other) { *this = other; }

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _size = other._size;
        _numbers = other._numbers;
    }
    return *this;
}

Span::Span(unsigned int size) : _size(size) {}

void Span::addNumber(int n)
{
    if (_numbers.size() < _size)
        _numbers.push_back(n);
    else
        throw std::exception();
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (_numbers.size() + std::distance(begin, end) <= _size)
        _numbers.insert(_numbers.end(), begin, end);
    else
        throw std::exception();
}

int Span::shortestSpan()
{
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (unsigned int i = 1; i < tmp.size(); i++)
        if (tmp[i] - tmp[i - 1] < min)
            min = tmp[i] - tmp[i - 1];
    return min;
}

int Span::longestSpan()
{
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}
