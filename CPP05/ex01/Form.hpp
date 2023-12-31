#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _sign;
        const int           _gradeSign;
        const int           _gradeExec;
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
    public:
        Form();
        ~Form();
        Form(const Form &other);
        Form &operator=(const Form &other);

        Form(const std::string name, int gradeSign, int gradeExec);
        void beSigned(const Bureaucrat &obj);
        std::string getName() const;
        bool        isSigned() const;
        int         getGradeSign() const;
        int         getGradeExec() const;
};

std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif