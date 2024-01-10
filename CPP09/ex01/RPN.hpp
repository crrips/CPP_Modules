#pragma once

#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<float> _data;
    public:
        RPN();
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);

        RPN (const std::string &arg);
};
