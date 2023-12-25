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

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}
