#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <sys/time.h>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::list<int> _list;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        PmergeMe(int sequence[], int size);

        void FordJohnsonVector(int begin, int end);
        void FordJohnsonList(int begin, int end);

        void vectorSort();
        void listSort();

        void printVector();
        void printList();
};
