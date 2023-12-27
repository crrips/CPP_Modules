#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : 
AForm("ShrubberyCreationForm", 145, 137), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        this->_target = other._target;
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    checkExec(executor);
    std::ofstream ofs;
    ofs.open(this->_target + "_shrubbery");
    ofs << "          &&& &&  & &&          " << std::endl;
    ofs << "      && &/&||& ()|/ @, &&     " << std::endl;
    ofs << "      &|/(/&/&||/& /_/)_&/_&    " << std::endl;
    ofs << "   &() &|/&|()|/&\\| '% & ()     " << std::endl;
    ofs << "  &_|_&&_| |& |&&/&__%_/_& &&   " << std::endl;
    ofs << "&&   && & &| &| /& & % ()& /&&  " << std::endl;
    ofs << " ()&_---()&&||&&-&&--%---()~   " << std::endl;
    ofs << "     &&      |||                " << std::endl;
    ofs << "             |||                " << std::endl;
    ofs << "             |||                " << std::endl;
    ofs << "             |||                " << std::endl;
    ofs << "       , -=-~  .-^- _           " << std::endl;
    ofs.close();
}
