
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : Form("No", false, R_SIGN, R_EXE, "RobotomyRequestForm")
{
    std::cout << "RobotomyRequestForm() " << *this << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& s)
{
    if (this != &s)
    {
        Form::operator=(s);
    }
    std::cout << "RobotomyRequestForm operator =  " << *this << std::endl;
    return(*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& s)
    : Form(s.getName(), s.getIsSigned(), s.getSignedGrade(), s.getExeGrade(), s.getType())
{
    std::cout << "RobotomyRequestForm copy  " << *this << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "~RobotomyRequestForm() " << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name)
    : Form(name, false, R_SIGN, R_EXE, "RobotomyRequestForm")
{
    std::cout << "RobotomyRequestForm(name) " << *this << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& exe) const
{
    try
    {
        if (getExeGrade() < exe.getGrade())
            throw (GradeTooLowException());
        else
        {
            std::cout << "drill sound...  : "; 
            std::srand(std::time(NULL));
            if (std::rand() % 2)
                std::cout << exe.getName() << " robotomized successfully" << std::endl;
            else
                std::cout << exe.getName() << " robotomized Fail ! ! ! " << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << exe.getName() << " can't exe " << "[" << getType() << "] "
            << getName() << " ";
        throw;
    }
}