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
        _data = other._data;
    return *this;
}

RPN::RPN(const std::string &arg)
{
    for (size_t i = 0; i < arg.size(); i++)
    {
        if (arg[i] == '+' || arg[i] == '-' || arg[i] == '*' || arg[i] == '/'
            || (arg[i] >= '0' && arg[i] <= '9') || arg[i] == ' ')
            continue ;
        std::cout << "Invalid expression" << std::endl;
        return ;
    }

    for (size_t i = 0; i < arg.size(); i++)
    {
        if (arg[i] == ' ')
            continue ;
        if (isdigit(arg[i]))
            _data.push(arg[i] - 48);
        else if (_data.size() <= 1)
        {
            std::cout << "Invalid expression" << std::endl;
            return ;
        }
        else
        {
            float a = _data.top();
            _data.pop();
            float b = _data.top();
            _data.pop();
            if (arg[i] == '+')
                _data.push(b + a);
            else if (arg[i] == '-')
                _data.push(b - a);
            else if (arg[i] == '*')
                _data.push(b * a);
            else if (arg[i] == '/')
            {
                if (a == 0)
                {
                    std::cout << "Invalid expression" << std::endl;
                    return ;
                }
                _data.push(b / a);
            }
        }
    }
    if (_data.size() != 1)
    {
        std::cout << "Invalid expression" << std::endl;
        return ;
    }
    while (!_data.empty())
    {
        std::cout << _data.top() << " ";
        _data.pop();
    }
    std::cout << std::endl;
}
