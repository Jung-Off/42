
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : Form("No", false, P_SIGN, P_EXE, "PresidentialPardonForm")
{
    std::cout << "PresidentialPardonForm() " << *this << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& s)
{
    if (this != &s)
    {
        Form::operator=(s);
    }
    std::cout << "PresidentialPardonForm operator =  " << *this << std::endl;
    return(*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& s)
    : Form(s.getName(), s.getIsSigned(), s.getSignedGrade(), s.getExeGrade(), s.getType())
{
    std::cout << "PresidentialPardonForm copy  " << *this << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "~PresidentialPardonForm() " << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name)
    : Form(name, false, P_SIGN, P_EXE, "PresidentialPardonForm")
{
    std::cout << "PresidentialPardonForm(name) " << *this << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& exe) const
{
    try
    {
        if (getExeGrade() < exe.getGrade())
            throw (GradeTooLowException());
        else
        {
            std::cout << exe.getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << exe.getName() << " can't exe " << "[" << getType() << "] "
            << getName() << " ";
        throw;
    }
}