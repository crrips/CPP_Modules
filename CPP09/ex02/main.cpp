#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    int sequence[argc - 1];

    if (argc < 2)
    {
        std::cout << "Invalid argument" << std::endl;
        return 1;
    }
    for (int i = 1; i < argc; i++)
    {
        if (!argv[i][0])
        {
            std::cout << "Invalid argument" << std::endl;
            return 2;
        }
        for (int j = 0; argv[i][j]; j++)
        {
            if (!isdigit(argv[i][j]))
            {
                std::cout << "Invalid argument" << std::endl;
                return 3;
            }
        }
        sequence[i - 1] = atoi(argv[i]);
    }

    std::cout << "Before: ";
    for (int i = 0; i < argc - 1; i++)
        std::cout << sequence[i] << " ";
    std::cout << std::endl;

    PmergeMe obj(sequence, argc - 1);

    struct timeval time;

    gettimeofday(&time, NULL);
    long vectorStart = time.tv_sec * 1000000LL + time.tv_usec;;
    obj.vectorSort();
    gettimeofday(&time, NULL);
    long vectorEnd = time.tv_sec * 1000000LL + time.tv_usec;;

    gettimeofday(&time, NULL);
    long listStart = time.tv_sec * 1000000LL + time.tv_usec;;
    obj.listSort();
    gettimeofday(&time, NULL);
    long listEnd = time.tv_sec * 1000000LL + time.tv_usec;;

    std::cout << "After: ";
    obj.printVector();
    // std::cout << "After: ";
    // obj.printList();

    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << (vectorEnd - vectorStart) / 1000.0 << " us" << std::endl;
    std::cout << "Time to process a range of " <<  argc - 1 << " elements with std::list : " << (listEnd - listStart) / 1000.0 << " us" << std::endl;

    return 0;
}
