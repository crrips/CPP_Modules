#include "ABC.hpp"

int main()
{
    A	a;
	B	b;
	C	c;

	Base::identify(&a);
	Base::identify(&b);
	Base::identify(&c);

	std::cout << std::endl;

	Base::identify(a);
	Base::identify(b);
	Base::identify(c);

	Base	*base = Base::generate();

	std::cout << std::endl << "Random: " << std::endl;

	Base::identify(base);
    Base::identify(*base);

    delete base;

    Base x;

	std::cout << std::endl;

    Base::identify(&x);
    Base::identify(x);

    return 0;
}
