#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	if (argc == 2)
	{
		harl.complain(argv[1]);
		return 0;
	}
	std::cout << "Usage: ./harlFilter [1-4]\n";
    return 0;
}
