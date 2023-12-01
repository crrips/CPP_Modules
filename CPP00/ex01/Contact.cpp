#include "Contact.hpp"

std::string Contact::getFirstName()
{
    return (this->_firstName);
}

std::string Contact::getLastName()
{
    return (this->_lastName);
}

std::string Contact::getNickName()
{
    return (this->_nickName);
}

std::string Contact::getPhoneNumber()
{
    return (this->_phoneNumber);
}

std::string Contact::getDarkSecret()
{
    return (this->_darkSecret);
}

void Contact::setFirstName(std::string firstName)
{
    this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
    this->_lastName = lastName;
}

void Contact::setNickName(std::string nickName)
{
    this->_nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
    this->_phoneNumber = phoneNumber;
}

void Contact::setDarkSecret(std::string darkSecret)
{
    this->_darkSecret = darkSecret;
}
