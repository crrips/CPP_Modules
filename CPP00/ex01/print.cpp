#include "PhoneBook.hpp"

std::string inputCheck(std::string str);

void printContact(Contact *contact)
{
    std::cout << std::endl;
    std::cout << "First name: " << contact->getFirstName() << std::endl;
    std::cout << "Last name: " << contact->getLastName() << std::endl;
    std::cout << "Nickname: " << contact->getNickName() << std::endl;
    std::cout << "Phone number: " << contact->getPhoneNumber() << std::endl;
    std::cout << "Dark secret: " << contact->getDarkSecret() << std::endl;
    std::cout << std::endl;
}

void printInfo(Contact *contact)
{
    std::cout << " | First name: " << std::setw(10) << inputCheck(contact->getFirstName());
    std::cout << " | Last name: " << std::setw(10) << inputCheck(contact->getLastName());
    std::cout << " | Nickname: " << std::setw(10) << inputCheck(contact->getNickName()) << " |" << std::endl;
    for (int i = 93; i > 0; i--)
        std::cout << "-";
    std::cout << std::endl;
}