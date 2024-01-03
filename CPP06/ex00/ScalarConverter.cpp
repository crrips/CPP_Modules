#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { *this = other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
        return *this;
    return *this;
}

void printInfo(char c, int i, float f, double d)
{
    if (c < 32 || c > 126)
        std::cout << "char:\tNon displayable" << std::endl;
    else
        std::cout << "char:\t'" << c << "'" << std::endl;
    std::cout << "int:\t" << i << std::endl;
    std::cout << "float:\t" << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double:\t" << std::fixed << std::setprecision(1) << d << std::endl;
}

void forChar(const std::string &input)
{
    int     i;
    float   f;
    double  d;

    if (input == "nan" || input == "nanf")
    {
        std::cout << "char:\timpossible" << std::endl;
        std::cout << "int:\timpossible" << std::endl;
        std::cout << "float:\tnanf" << std::endl;
        std::cout << "double:\tnan" << std::endl;
        return ;
    }
    else if (input == "+inf" || input == "+inff")
    {
        std::cout << "char:\timpossible" << std::endl;
        std::cout << "int:\timpossible" << std::endl;
        std::cout << "float:\tinf" << std::endl;
        std::cout << "double:\tinf" << std::endl;
        return ;
    }
    else if (input == "-inf" || input == "-inff")
    {
        std::cout << "char:\timpossible" << std::endl;
        std::cout << "int:\timpossible" << std::endl;
        std::cout << "float:\t-inf" << std::endl;
        std::cout << "double:\t-inf" << std::endl;
        return ;
    }
    if (input.length() > 1)
    {
        std::cout << "Invalid input" << std::endl;
        return ;
    }
    i = static_cast<int>(input[0]);
    f = static_cast<float>(input[0]);
    d = static_cast<double>(input[0]);

    printInfo(input[0], i, f, d);
}

void forDigit(const std::string &input)
{
    int     c;
    float   f;
    double  d;

    double  i;
    bool    dot = 0;

    for (size_t i = 0; i < input.length(); i++)
    {
        if (i == 0 && (input[i] == '+' || input[i] == '-'))
            continue ;
        if (i == input.length() - 1 && input[i] == 'f')
            break ;
        if (input[i] == '.' && (i != 0 || i != input.length() - 1))
        {
            if (dot == 0)
                dot = 1;
            else
            {
                std::cout << "Invalid input" << std::endl;
                return ;
            }
        }
        if (!isdigit(input[i]) && input[i] != '.')
        {
            std::cout << "Invalid input" << std::endl;
            return ;
        }
    }

    if (dot == 1)
        i = atof(input.c_str());
    else
        i = atoi(input.c_str());
    c = static_cast<char>(i);
    f = static_cast<float>(i);
    d = static_cast<double>(i);

    printInfo(c, i, f, d);
}

void checkType(const std::string &input)
{
    if (isalpha(input[0]))
        forChar(input);
    else if (isdigit(input[0]) || input[0] == '+' || input[0] == '-')
        forDigit(input);
    else
    {
        std::cout << "Invalid input" << std::endl;
        return ;
    }
}

void ScalarConverter::convert(const std::string &input)
{
    if (input.empty())
    {
        std::cout << "empty input" << std::endl;
        return ;
    }

    checkType(input);
}
