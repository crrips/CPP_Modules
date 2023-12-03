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

void emptyCheck(std::string *str)
{
	if (str->empty())
	{
		std::cout << "error: empty string. Try again: ";
		std::getline(std::cin, *str);
		if (std::cin.eof()) {exit(1);}
		emptyCheck(str);
	}
}

void onlyLetters(std::string *str)
{
	for (size_t i = 0; i < str->length(); i++)
	{
		if (!isalpha((*str)[i]))
		{
			std::cout << "error: only letters. Try again: ";
			std::getline(std::cin, *str);
			emptyCheck(str);
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
			emptyCheck(str);
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

std::string addData(std::string str)
{
	std::string input;

	std::cout << str;
	std::getline(std::cin, input);
	emptyCheck(&input);
	if (std::cin.eof()) {exit(1);}
	return input;
}
