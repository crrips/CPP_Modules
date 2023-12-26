#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat dovbyk("Artem Dovbyk", 42);
        std::cout << dovbyk << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
