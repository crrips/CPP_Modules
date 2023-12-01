#include "PhoneBook.hpp"

std::string inputCheck(std::string str)
{
	if (str.length() > 10)
	{
		str.erase(9, str.length() - 9);
		str.append(".");
	}
	return str;
}

void onlyLetters(std::string *str)
{
	for (size_t i = 0; i < str->length(); i++)
	{
		if (!isalpha((*str)[i]))
		{
			std::cout << "error: only letters. Try again: ";
			std::getline(std::cin, *str);
			if (std::cin.eof()) {exit(1);}
			onlyLetters(str);
		}
	}
}

void onlyDigits(std::string *str)
{
	for (size_t i = 0; i < str->length(); i++)
	{
		if (!isdigit((*str)[i]))
		{
			std::cout << "error: only digits. Try again: ";
			std::getline(std::cin, *str);
			if (std::cin.eof()) {exit(1);}
			onlyDigits(str);
		}
	}
}

int	checkNumInstring(std::string *str)
{
	for (size_t i = 0; i < str->length(); i++)
	{
		if (isdigit((*str)[i]))
			return 1;
	}
	return 0;
}
