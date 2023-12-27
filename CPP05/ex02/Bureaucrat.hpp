#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
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
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);

        Bureaucrat(const std::string name, int grade);
        
        std::string getName() const;
        int         getGrade() const;
        void        signForm(AForm &obj) const;
        void        executeForm(AForm const & form);
        void        increment();
        void        decrement();

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif