
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    public:
        Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat &b);
        Bureaucrat(const Bureaucrat& B);
        ~Bureaucrat();

        Bureaucrat(const std::string name, const int grade);
        
        std::string getName() const;
        int getGrade() const;
        void increGrade(int i); //(2 -> 1)
        void decreGrade(int i); //(1 -> 2)

        //관료자에 >> signForm 함수추가 >> 정해진 문구
        void signForm(Form &f);

        class GradeTooHighException : public std::exception
        {
            public:
                const char * what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char * what() const throw();
        };

        void executeForm(Form const & form);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& b);

#endif