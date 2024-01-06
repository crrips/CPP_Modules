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

    std::cout << "Loading data from " << filename << std::endl;
    std::string line;
    std::getline(file, line);
    // while (std::getline(file, line))
    // {
    //     std::string date = line.substr(0, line.find(','));
    //     line.erase(0, line.find(',') + 1);
    //     std::string price = line.substr(0, line.find(','));
    //     _data[date] = std::stod(price);
    // }

    for (std::map<std::string, double>::const_iterator it = _data.begin(); it != _data.end(); it++)
        std::cout << it->first << ": " << it->second << std::endl;

    file.close();
    data.close();
}
