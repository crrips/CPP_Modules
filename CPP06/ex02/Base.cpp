#include "Base.hpp"
#include "ABC.hpp"

Base::~Base() {}

Base * Base::generate(void)
{
    srand(time(NULL));
    int random = rand() % 3;
    if (random == 0)
        return new A;
    else if (random == 1)
        return new B;
    else
        return new C;
}

void Base::identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cerr << "Error with identifying" << std::endl;
}

void Base::identify(Base& p)
{
    try
    {
        p = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e)
    {
        try
        {
            p = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch (std::exception &e)
        {
            try
            {
                p = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch (std::exception &e)
            {
                std::cerr << "Error with identifying" << std::endl;
            }
        }
    }
}
