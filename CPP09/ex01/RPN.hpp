#pragma once

#include <iostream>
#include <vector>

class RPN
{
    private:
        std::vector<std::string> _data;
    public:
        RPN();
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);

        RPN (const std::string &arg);
};
