#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
        *this = other;    
    return *this;
}

PmergeMe::PmergeMe(int sequence[], int size)
{
    for (int i = 0; i < size; i++)
        _vector.push_back(sequence[i]);
    for (int i = 0; i < size; i++)
        _list.push_back(sequence[i]);
}

void listInplaceMerge(std::list<int> &list, int begin, int middle, int end)
{
    std::list<int> left;
    std::list<int> right;
    std::list<int>::iterator it = list.begin();
    for (int i = 0; i < begin; i++)
        it++;
    for (int i = begin; i < middle; i++)
    {
        left.push_back(*it);
        it++;
    }
    for (int i = middle; i < end; i++)
    {
        right.push_back(*it);
        it++;
    }
    it = list.begin();
    for (int i = 0; i < begin; i++)
        it++;
    while (!left.empty() && !right.empty())
    {
        if (left.front() < right.front())
        {
            *it = left.front();
            left.pop_front();
        }
        else
        {
            *it = right.front();
            right.pop_front();
        }
        it++;
    }
    while (!left.empty())
    {
        *it = left.front();
        left.pop_front();
        it++;
    }
    while (!right.empty())
    {
        *it = right.front();
        right.pop_front();
        it++;
    }
}

void PmergeMe::FordJohnsonVector(int begin, int end)
{
    if (end - begin <= 1)
        return;
    int middle = (begin + end) / 2;
    FordJohnsonVector(begin, middle);
    FordJohnsonVector(middle, end);
    std::inplace_merge(_vector.begin() + begin, _vector.begin() + middle, _vector.begin() + end);
}

void PmergeMe::FordJohnsonList(int begin, int end)
{
    if (end - begin <= 1)
        return;
    int middle = (begin + end) / 2;
    FordJohnsonList(begin, middle);
    FordJohnsonList(middle, end);
    listInplaceMerge(_list, begin, middle, end);
}

void PmergeMe::vectorSort()
{
    FordJohnsonVector(0, _vector.size());
}

void PmergeMe::listSort()
{
    FordJohnsonList(0, _list.size());
}

void PmergeMe::printVector()
{
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::printList()
{
    for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}
