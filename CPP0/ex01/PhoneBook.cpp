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
	string	index;
	int		i;

	if (book[0].firstName.empty())
	{
		cout << "error: no contacts" << endl << endl;
		return ;
	}
	for (int i = 93; i > 0; i--)
		cout << "-";
	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		if (book[i].firstName.empty())
			break ;
		cout << "| Index: " << std::setw(10) << i;
		book[i].printInfo();
	}
	cout << "Enter index: ";
	cin >> index;
	inputCheck(&index);	
	if (index.length() != 1 || !checkNumInString(&index))
	{
		cout << "\nerror: incorrect index" << endl;
		printAll(book);
		return ;
	}
	i = std::stoi(index);
	if (i >= 0 && i < 8 && !book[i].firstName.empty())
	{
		book[i].printContact();
		cout << endl;
	}
	else
	{
		cout << "\nerror: incorrect index" << endl;
		printAll(book);
	}
}	
