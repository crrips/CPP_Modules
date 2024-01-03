#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> intArrEmpty(0);

    std::cout << "intArrEmpty.size(): "<< intArrEmpty.size() << std::endl << std::endl;

	Array<int> intArr(5);
	Array<double> doubleArr(5);

	for (size_t i = 0; i < intArr.size(); i++)
		intArr[i] = i;

	for (size_t i = 0; i < doubleArr.size(); i++)
		doubleArr[i] = i + 0.42;

	std::cout << "intArr: " << std::endl;
	for (size_t i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << std::endl;
	std::cout << std::endl;

	std::cout << "doubleArr: " << std::endl;
	for (size_t i = 0; i < doubleArr.size(); i++)
		std::cout << doubleArr[i] << std::endl;

	try
    {
		std::cout << std::endl << "intArr[6]: " << intArr[6] << std::endl;
	}
	catch (std::exception &e)
    {

		std::cout << "Error: " << e.what() << std::endl;
	}

    // Array<int> numbers(MAX_VAL);
    // int* mirror = new int[MAX_VAL];
    // srand(time(NULL));
    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     const int value = rand();
    //     numbers[i] = value;
    //     mirror[i] = value;
    // }
    // //SCOPE
    // {
    //     Array<int> tmp = numbers;
    //     Array<int> test(tmp);
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     if (mirror[i] != numbers[i])
    //     {
    //         std::cerr << "didn't save the same value!!" << std::endl;
    //         return 1;
    //     }
    // }
    // try
    // {
    //     numbers[-2] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //     numbers[MAX_VAL] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     numbers[i] = rand();
    // }
    // delete [] mirror;//
    return 0;
}
