
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& B);
        Bureaucrat& operator=(const Bureaucrat& B);
        ~Bureaucrat();

        Bureaucrat(const std::string name, const int grade);
        std::string getName()const;
        int getGrade()const;

        void gradeHigher(int i);
        void gradeLower(int i);
        //gradeHigher 1
        //gradeLower 150

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
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &B);

#endif