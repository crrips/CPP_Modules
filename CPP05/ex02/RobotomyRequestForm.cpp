#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : 
AForm("RobotomyRequestForm", 72, 45), _target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        this->_target = other._target;
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
AForm("RobotomyRequestForm", 72, 45), _target(target) {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    checkExec(executor);
    std::cout << "*DRILLING NOISE*" << std::endl;
    if (rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized" << std::endl;
    else
        std::cout << this->_target << " robotomy failed" << std::endl;
}
