#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _data.clear();
        _data = other._data;
    }
    return *this;
}

bool checkNum(float num)
{
    if (num <= 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    else if (num > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    else if (num < 0.00001)
    {
        std::cout << "Error: too small a number." << std::endl;
        return false;
    }
    return true;
}

bool checkYear(const std::string &date)
{
    if (atoi(date.substr(0, 4).c_str()) < 2009 || atoi(date.substr(0, 4).c_str()) > 2021)
    {
        std::cout << "Error: bad date format." << std::endl;
        return false;
    }
    return true;
}

bool checkMonth(const std::string &date)
{
    if (atoi(date.substr(5, 2).c_str()) > 12 || atoi(date.substr(5, 2).c_str()) < 1)
    {
        std::cout << "Error: bad date format." << std::endl;
        return false;
    }
    return true;
}

bool checkDay(const std::string &date)
{
    if (atoi(date.substr(8, 2).c_str()) > 31 || atoi(date.substr(8, 2).c_str()) < 1)
    {
        std::cout << "Error: bad date format." << std::endl;
        return false;
    }
    if (atoi(date.substr(5, 2).c_str()) == 2 && atoi(date.substr(8, 2).c_str()) > 29)
    {
        std::cout << "Error: bad date format." << std::endl;
        return false;
    }
    if (atoi(date.substr(5, 2).c_str()) == 2 && atoi(date.substr(8, 2).c_str()) == 29 && atoi(date.substr(0, 4).c_str()) % 4 != 0)
    {
        std::cout << "Error: bad date format." << std::endl;
        return false;
    }
    if ((atoi(date.substr(5, 2).c_str()) == 4 || atoi(date.substr(5, 2).c_str()) == 6 || atoi(date.substr(5, 2).c_str()) == 9 || atoi(date.substr(5, 2).c_str()) == 11) && atoi(date.substr(8, 2).c_str()) > 30)
    {
        std::cout << "Error: bad date format." << std::endl;
        return false;
    }
    return true;
}

bool checkDate(const std::string &date)
{
    if (date.size() != 10)
    {
        std::cout << "Error: bad date format." << std::endl;
        return false;
    }
    if (!checkYear(date) || !checkMonth(date) || !checkDay(date))
        return false;
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
            {
                std::cout << "Error: bad date format." << std::endl;
                return false;
            }
        }
        else if (date[i] < '0' || date[i] > '9')
        {
            std::cout << "Error: bad date format." << std::endl;
            return false;
        }
    }
    return true;
}

float calc(const std::string &date, float btc, std::map<std::string, float> &data)
{
    for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); it++)
    {
        if (it->first == date.substr(0, date.find(' ')))
            return btc * it->second;
    }
    for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); it++)
    {
        if (it->first > date.substr(0, date.find(' ')))
        {
            float price = it->second;
            it--;
            float price2 = it->second;
            float diff = price - price2;
            float days = (float)(atoi(date.substr(0, date.find('-')).c_str()) - atoi(it->first.substr(0, it->first.find('-')).c_str()));
            return btc * (price2 + (diff / 30 * days));
        }
    }
    return 0;
}

bool checkVal(const std::string &line, const std::string &strPrice)
{
    for (size_t i = 0; i < strPrice.size(); i++)
    {
        if (!isdigit(strPrice[i]) && strPrice[i] != '.' && strPrice[i] != ' ')
        {
            std::cout << "Error: bad input => " << line << std::endl;
            return false;
        }
        if (i == strPrice.size() - 1 && strPrice[i] == '.')
        {
            std::cout << "Error: bad input => " << line << std::endl;
            return false;
        }
    }
    return true;
}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        return ;
    }
    std::ifstream data("data.csv");
    if (!data.is_open())
    {
        std::cout << "Error: could not open data.csv" << std::endl;
        return ;
    }

    std::string line;
    std::getline(data, line);
    if (line != "date,exchange_rate")
    {
        std::cout << "Error: bad data.csv" << std::endl;
        return ;
    }
    while (std::getline(data, line))
    {
        std::string date = line.substr(0, line.find(','));
        std::string price = line.substr(line.find(',') + 1);
        _data[date] = atof(price.c_str());
    }
    data.close();

    std::getline(file, line);
    if (line != "date | value" || !std::getline(file, line))
    {
        std::cout << "Error: bad input" << std::endl;
        return ;
    }

    do
    {
        if (line.find('|') == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue ;
        }
        std::string date = line.substr(0, line.find('|'));
        std::string strPrice = line.substr(line.find('|') + 1);
        
        float price = atof(strPrice.c_str());
        if (!checkDate(date.substr(0, date.find(' '))) || !checkVal(line, strPrice) || !checkNum(price))
            continue ;
        std::cout << date << " => " << price << " = " << calc(date, price, _data) << std::endl;
    } while (std::getline(file, line));

    file.close();
}
