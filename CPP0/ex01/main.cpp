#include "PhoneBook.hpp"

int main()
{
    PhoneBook	book[8];
	string		input;

	while (true)
	{
		cout << "ADD | SEARCH | EXIT\n" << "Select command: ";
		cin >> input;
		inputCheck(&input);
		if (input == "ADD")
			addContact(book);
		else if (input == "SEARCH")
			printAll(book);
		else if (input == "EXIT")
			exit(0);
		else
		{
			cout << "\nerror: incorrect input:" << input << endl;
			continue ;
		}
	}
    return (0);
}