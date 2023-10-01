#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void	inputCheck(string *str);

class PhoneBook
{
	public:
	string firstName;
	string lastName;
	string nickName;
	string phoneNumber;
	string darkSecret;

	void	addNew()
	{
		cout << "Enter first name: ";
		cin >> this->firstName;
		inputCheck(&this->firstName);
		cout << "Enter last name: ";
		cin >> this->lastName;
		inputCheck(&this->lastName);
		cout << "Enter nickname: ";
		cin >> this->nickName;
		inputCheck(&this->nickName);
		cout << "Enter phone number: ";
		cin >> this->phoneNumber;
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
		cout << "| Phone number: " << std::setw(10) << phoneNumber; //<< endl;
		cout << " | Dark secret: " << std::setw(10) << darkSecret << " |" << endl;
		for (int i = 54; i > 0; i--)
			cout << "-";
		cout << endl;
	}

	void	printInfo()
	{
		cout << " | First name: " << std::setw(10) << firstName; //<< endl;
		cout << " | Last name: " << std::setw(10) << lastName; //<< endl;
		cout << " | Nickname: " << std::setw(10) << nickName << " |" << endl;
		for (int i = 93; i > 0; i--)
			cout << "-";
		cout << endl;
	}
};

#endif