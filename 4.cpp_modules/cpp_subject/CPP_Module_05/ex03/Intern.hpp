
#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    private:

    public:
        enum { S, R, P, MAX };
        Intern();
        Intern& operator=(const Intern& i);
        Intern(const Intern& i);
        ~Intern();

        class notypeException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        Form *makeForm(const std::string type, const std::string name);
};

#endif