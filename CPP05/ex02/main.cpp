#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("Artem Dovbyk", 137);
        ShrubberyCreationForm form("ShrubberyCreationForm");

		bureaucrat.executeForm(form);
        bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
        std::cout << form;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    // for(int i = 0; i < 10; i++) // to check random is works correctly
    try
    {
        Bureaucrat bureaucrat("Artem Dovbyk", 1);
        RobotomyRequestForm form("RobotomyRequestForm");

		bureaucrat.executeForm(form);
        bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
        std::cout << form;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
	try
    {
        Bureaucrat bureaucrat("Artem Dovbyk", 1);
        PresidentialPardonForm form("PresidentialPardonForm");

		bureaucrat.executeForm(form);
        bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
        std::cout << form;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	return 0;
}