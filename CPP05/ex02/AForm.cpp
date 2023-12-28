#include "AForm.hpp"

AForm::AForm() : _name(), _sign(0), _gradeSign(1), _gradeExec(1) {}

AForm::~AForm() {}

AForm::AForm(const AForm &other) : _name(other._name), _sign(other._sign),
_gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->_sign = other._sign;
    return *this;
}

AForm::AForm(const std::string name, int gradeSign, int gradeExec) : _name(name),
_gradeSign(gradeSign), _gradeExec(gradeExec) {}

void AForm::beSigned(const Bureaucrat &obj)
{
    if (obj.getGrade() <= this->_gradeSign)
        this->_sign = 1;
    else
        throw GradeTooLowException();
}

void AForm::checkExec(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getGradeExec())
        throw GradeTooLowException();
    else if (!this->isSigned())
        throw NotSigned();
}

std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::isSigned() const
{
    return this->_sign;
}

int AForm::getGradeSign() const
{
    return this->_gradeSign;
}

int AForm::getGradeExec() const
{
    return this->_gradeExec;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}
const char *AForm::NotSigned::what() const throw()
{
    return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
    out << "Form: " << obj.getName() << std::endl;
    out << "Signed: " << obj.isSigned() << std::endl;
    out << "Signed grade: " << obj.getGradeSign() << std::endl;
    out << "Executed grade: " << obj.getGradeExec() << std::endl;
    return (out);
}
