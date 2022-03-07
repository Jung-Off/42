
#include "Intern.hpp"

Intern::Intern()
    {}

Intern& Intern::operator=(const Intern& i)
{
    if (this != &i)
        return (*this);
    return (*this);
}

Intern::Intern(const Intern& i)
{
    *this = i;
}

Intern::~Intern()
    {}

const char* Intern::notypeException::what() const throw()
{
    return ("no Match Type!");
}


Form* Intern::makeForm(const std::string type, const std::string name)
{
    std::string a[Intern::MAX] = {"shrubbery request", "robotomy request", "presidential request"};
    int i;

    for (i = 0; i < Intern::MAX; i++)
    {
        if (a[i] == type)
            break;
    }
    Form *form;
    switch (i)
    {
        case Intern::S:
            form = new ShrubberyCreationForm(name);
            break;
        case Intern::R:
            form = new RobotomyRequestForm(name);
            break;
        case Intern::P:
            form = new PresidentialPardonForm(name);
            break;
        default:
            throw notypeException();
            break;
    }
    std::cout << "Intern works !! " << type << " " << name << std::endl;
    return (form);
}