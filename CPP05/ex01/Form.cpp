#include "Form.hpp"

Form::Form() : _name(), _sign(0), _gradeSign(1), _gradeExec(1) {}

Form::~Form() {}

Form::Form(const Form &other) : _name(other._name), _sign(other._sign),
_gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->_sign = other._sign;
    return *this;
}

Form::Form(const std::string name, int gradeSign, int gradeExec) : _name(name),
_gradeSign(gradeSign), _gradeExec(gradeExec) {}

void Form::beSigned(const Bureaucrat &obj)
{
    if (obj.getGrade() <= this->_gradeSign)
        this->_sign = 1;
    else
        throw GradeTooLowException();
}

std::string Form::getName() const
{
    return this->_name;
}

bool Form::isSigned() const
{
    return this->_sign;
}

int Form::getGradeSign() const
{
    return this->_gradeSign;
}

int Form::getGradeExec() const
{
    return this->_gradeExec;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    out << "Form: " << obj.getName() << std::endl;
    out << "Signed: " << obj.isSigned() << std::endl;
    out << "Signed grade: " << obj.getGradeSign() << std::endl;
    out << "Executed grade: " << obj.getGradeExec() << std::endl;
    return (out);
}
