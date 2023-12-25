#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bober("Bober", 42);
        std::cout << bober << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
