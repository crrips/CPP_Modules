#include "Intern.hpp"

int main()
{
    Bureaucrat bureaucrat("a", 1);
    Intern someRandomIntern;
    AForm* rrf;
    
    rrf = someRandomIntern.makeForm("shrubbery creation", "Messi");
    bureaucrat.signForm(*rrf);
    bureaucrat.executeForm(*rrf);
    delete rrf;
    std::cout << std::endl;

    rrf = someRandomIntern.makeForm("robotomy request", "Suarez");
    bureaucrat.signForm(*rrf);
    bureaucrat.executeForm(*rrf);
    delete rrf;
    std::cout << std::endl;

    rrf = someRandomIntern.makeForm("presidential pardon", "Neymar");
    bureaucrat.signForm(*rrf);
    bureaucrat.executeForm(*rrf);
    delete rrf;
    std::cout << std::endl;

    try
    {
        rrf = someRandomIntern.makeForm("SHRUBERRY", "Billy");
        bureaucrat.signForm(*rrf);
        bureaucrat.executeForm(*rrf);
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    try
    {
        rrf = someRandomIntern.makeForm("shrubbery creation", "");
        bureaucrat.signForm(*rrf);
        bureaucrat.executeForm(*rrf);
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	return 0;
}
