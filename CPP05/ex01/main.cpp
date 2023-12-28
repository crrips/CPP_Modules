#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
    {
        Bureaucrat bureaucrat("Artem Dovbyk", 10);
        Form form("forma", 15, 20);

        bureaucrat.signForm(form);

        std::cout << form;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	return 0;
}