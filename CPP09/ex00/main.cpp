#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./btc [file]" << std::endl;
        return 1;
    }
    BitcoinExchange btc(argv[1]);
    return 0;
}

