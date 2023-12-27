#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        class InvalidForm : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class InvalidTarget : public std::exception
        {
            public:
                const char *what() const throw();
        };
    public:
        Intern();
        ~Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);

        AForm *makeForm(const std::string &form, const std::string &target);
};
