#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info(void)
{
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]\n";
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
    if (level.length() != 1 || level.at(0) < '1' || level.at(0) > '4')
    {
        std::cout << "Usage: ./harlFilter [1-4]\n";
        return ;
    }
    int i = std::stoi(level);
    void (Harl::*arr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    switch (i)
    {
    case 1:
        (this->*arr[0])();
    case 2:
        (this->*arr[1])();
    case 3:
        (this->*arr[2])();
    case 4:
        (this->*arr[3])();
        break;
    
    default:
        std::cout << "Usage: ./harlFilter [1-4]\n";
        break;
    }
}
