#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern &Intern::operator=(const Intern &other)
{
    if (this != &other)
        return *this;
    return *this;
}

AForm *Intern::makeForm(const std::string &form, const std::string &target)
{
    AForm   *ret = NULL;
    int     i = 0;
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon",};

    if (target.empty())
        throw InvalidTarget();

    for(; i < 3; i++)
        if (forms[i] == form)
            break;
    switch (i)
    {
    case 0:
        ret = new ShrubberyCreationForm(target);
        std::cout << "Intern creates " << form << std::endl;
        break;
    case 1:
        ret = new RobotomyRequestForm(target);
        std::cout << "Intern creates " << form << std::endl;
        break;
    case 2:
        ret = new PresidentialPardonForm(target);
        std::cout << "Intern creates " << form << std::endl;
        break;
    default:
        throw InvalidForm();
        break;
    }
    return ret;
}

const char *Intern::InvalidForm::what() const throw()
{
    return ("Invalid form");
}

const char *Intern::InvalidTarget::what() const throw()
{
    return ("Invalid target");
}
