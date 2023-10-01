#include "PhoneBook.hpp"

void	inputCheck(string *str)
{
	if (cin.eof())
	{
		cout << "\nerror: empty input" << endl;
		exit(1);
	}
	if (str->length() > 10)
	{
		str->erase(9, str->length() - 9);
		str->append(".");
	}
}

void	addContact(PhoneBook *book)
{
	static int	c = 0;

	if (c != 0)
	{
		for (int i = 7; i > 0; i--)
		{
			book[i].firstName	= book[i - 1].firstName;
			book[i].lastName	= book[i - 1].lastName;
			book[i].nickName	= book[i - 1].nickName;
			book[i].phoneNumber	= book[i - 1].phoneNumber;
			book[i].darkSecret	= book[i - 1].darkSecret;
		}
	}
	book->addNew();
	cout << "Contact successfully added!" << endl << endl;
	c++;
}

int	checkNumInString(string *str)
{
	for (size_t i = 0; i < str->length(); i++)
	{
		if (isdigit((*str)[i]))
			return 1;
	}
	return 0;
}

void	printAll(PhoneBook *book)
{
	int		index;
	string	str;

	for (int i = 93; i > 0; i--)
		cout << "-";
	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		if (book[i].firstName.empty())
			continue ;
		cout << "| Index: " << std::setw(10) << i + 1;// << endl;
		book[i].printInfo();
	}
	if (book[0].firstName.empty())
	{
		cout << "error: no contacts" << endl << endl;
		return ;
	}
	cout << "Enter index: ";
	cin >> index;
	str = std::to_string(index);
	if (cin.eof() || str.length() != 1 || checkNumInString(&str))
	{
		cout << "error: incorrect index" << endl;
		exit(1);
	}
	if (index > 0 && index < 9 && !book[index - 1].firstName.empty())
	{
		book[index - 1].printContact();
		cout << endl;
	}
	else
	{
		cout << "error: incorrect index" << endl;
		exit(1);
	}
}

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
			cout << "error: incorrect input" << endl << endl;
			continue ;
		}
	}
    return (0);
}
