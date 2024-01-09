#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        _data.clear();
        _data = other._data;
    }
    return *this;
}

bool checkIllegal(const std::string &arg)
{
    for (size_t i = 0; i < arg.size(); i++)
    {
        if (arg[i] == '+' || arg[i] == '-' || arg[i] == '*' || arg[i] == '/')
            continue ;
        if (arg[i] >= '0' && arg[i] <= '9')
            continue ;
        if (arg[i] == ' ')
            continue ;
        return false;
    }
    return true;
}

RPN::RPN(const std::string &arg)
{
    if (arg.empty())
    {
        std::cout << "Error: empty argument" << std::endl;
        return ;
    }
    if (!checkIllegal(arg))
    {
        std::cout << "Error: illegal argument" << std::endl;
        return ;
    }
}
