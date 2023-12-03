#include "PhoneBook.hpp"

int main()
{
    PhoneBook		book;
	std::string		input;

	while (true)
	{
		std::cout << "ADD | SEARCH | EXIT\n" << "Select command: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) {exit(1);}
		if (input == "ADD")
			book.add();
		else if (input == "SEARCH")
			book.search();
		else if (input == "EXIT")
			exit(0);
		else
		{
			std::cout << "error: incorrect input:" << input << std::endl << std::endl;
			continue ;
		}
	}
    return (0);
}
