#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void	inputCheck(string *str);
void	addContact(PhoneBook *book);
void	printAll(PhoneBook *book);

class Contact
{
    public:
    string firstName;
    string lastName;
    string nickName;
    string phoneNumber;
    string darkSecret;
};

class PhoneBook : public Contact
{
	public:

	void	onlyLetters(string *str)
	{
		for (size_t i = 0; i < str->length(); i++)
		{
			if (!isalpha((*str)[i]))
			{
				cout << "error: only letters. Try again: ";
				cin >> *str;
				onlyLetters(str);
			}
		}
	}

	void	onlyDigits(string *str)
	{
		for (size_t i = 0; i < str->length(); i++)
		{
			if (!isdigit((*str)[i]))
			{
				cout << "error: only digits. Try again: ";
				cin >> *str;
				onlyDigits(str);
			}
		}
	}

	void	addNew()
	{
		cout << "Enter first name: ";
		cin >> this->firstName;
		onlyLetters(&this->firstName);
		inputCheck(&this->firstName);
		cout << "Enter last name: ";
		cin >> this->lastName;
		onlyLetters(&this->lastName);
		inputCheck(&this->lastName);
		cout << "Enter nickname: ";
		cin >> this->nickName;
		inputCheck(&this->nickName);
		cout << "Enter phone number: ";
		cin >> this->phoneNumber;
		onlyDigits(&this->phoneNumber);
		inputCheck(&this->phoneNumber);
		cout << "Enter dark secret: ";
		cin >> this->darkSecret;
		inputCheck(&this->darkSecret);
	}

	void	printContact()
	{
		for (int i = 54; i > 0; i--)
			cout << "-";
		cout << endl;
		cout << "| Phone number: " << std::setw(10) << phoneNumber;
		cout << " | Dark secret: " << std::setw(10) << darkSecret << " |" << endl;
		for (int i = 54; i > 0; i--)
			cout << "-";
		cout << endl;
	}

	void	printInfo()
	{
		cout << " | First name: " << std::setw(10) << firstName;
		cout << " | Last name: " << std::setw(10) << lastName;
		cout << " | Nickname: " << std::setw(10) << nickName << " |" << endl;
		for (int i = 93; i > 0; i--)
			cout << "-";
		cout << endl;
	}
};

#endif