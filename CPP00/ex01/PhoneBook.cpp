#include "PhoneBook.hpp"

void	onlyLetters(std::string *str);
void	onlyDigits(std::string *str);
void	emptyCheck(std::string *str);
int		checkNumInstring(std::string *str);

void	printContact(Contact *contact);
void	printInfo(Contact *contact);

std::string addData(std::string str);

void addNew(Contact *book)
{
    std::string input;

	input = addData("Enter first name: ");
    onlyLetters(&input);
	book->setFirstName(input);
	input = addData("Enter last name: ");
    onlyLetters(&input);
	book->setLastName(input);
	input = addData("Enter nickname: ");
	book->setNickName(input);
	input = addData("Enter phone number: ");
    onlyDigits(&input);
	book->setPhoneNumber(input);
	input = addData("Enter dark secret: ");
	book->setDarkSecret(input);
}

void	PhoneBook::add()
{
	static int	c = 0;

	if (c != 0)
	{
		for (int i = 7; i > 0; i--)
			this->_contact[i] = this->_contact[i - 1];
	}
	addNew(&this->_contact[0]);
	std::cout << "Contact successfully added! 🤠" << std::endl << std::endl;
	c++;
}

void	PhoneBook::search()
{
	std::string	index;
	int		i;

	if (this->_contact[0].getFirstName().empty())
	{
		std::cout << "error: no contacts" << std::endl << std::endl;
		return ;
	}
	for (int i = 93; i > 0; i--)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->_contact[i].getFirstName().empty())
			break ;
		std::cout << "| Index: " << std::setw(10) << i;
		printInfo(&this->_contact[i]);
	}
	std::cout << "Enter index: ";
	std::getline(std::cin, index);
	if (std::cin.eof()) {exit(1);}
	if (index.length() != 1 || !checkNumInstring(&index))
	{
		std::cout << "\nerror: incorrect index" << std::endl;
		search();
		return ;
	}
	i = std::stoi(index);
	if (i >= 0 && i < 8 && !this->_contact[i].getFirstName().empty())
	{
		printContact(&this->_contact[i]);
		std::cout << std::endl;
	}
	else
	{
		std::cout << "\nerror: incorrect index" << std::endl;
		search();
	}
}
