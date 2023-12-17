#include "Cat.hpp"
#include "Dog.hpp"

#define AMOUNT 6

int main()
{

    // const Animal *a = new Animal();
    if (AMOUNT <= 0)
    {
        std::cout << "wtf bro" << std::endl;
        return 0;
    }

    const Animal *zoo[AMOUNT];

    for (int i = 0; i < AMOUNT / 2; i++)
        zoo[i] = new Dog();
    for (int i = AMOUNT / 2; i < AMOUNT; i++)
        zoo[i] = new Cat();

    zoo[0]->makeSound();
    zoo[AMOUNT / 2]->makeSound();

    for (int i = 0; i < AMOUNT; i++)
        delete zoo[i];

    return 0;
}

// int main()
// {
//     main2();
//     system("leaks brain");
// }
