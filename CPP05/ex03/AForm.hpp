#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
        class NotSigned : public std::exception
        {
            public:
                const char *what() const throw();
        };
    public:
        AForm();
        virtual ~AForm();
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);

        AForm(const std::string name, int gradeSign, int gradeExec);
        void beSigned(const Bureaucrat &obj);
        void checkExec(Bureaucrat const & executor) const;
        virtual void execute(Bureaucrat const & executor) const = 0;
        std::string getName() const;
        bool        isSigned() const;
        int         getGradeSign() const;
        int         getGradeExec() const;
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif