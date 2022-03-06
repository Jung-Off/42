
#include "Form.hpp"

Form::Form()
    :   _name("NONAME"), _isSigned(false), _signedGrade(1), _exeGrade(1)
{
    std::cout << "Form() " << *this << std::endl;
}

Form& Form::operator=(const Form& f)
{
    if (this != &f)
    {
        if (_signedGrade > 150 || _exeGrade > 150)
            throw (GradeTooLowException());
        else if (_signedGrade < 1 || _exeGrade < 1)
            throw (GradeTooHighException());

        (std::string&)_name = f.getName();
        _isSigned = f.getIsSigned();
        (int&)_signedGrade = f.getSignedGrade();
        (int&)_exeGrade = f.getExeGrade();
        std::cout << "operator =  " << *this << std::endl;
    }
    return (*this);
}

Form::Form(const Form& f)
    :   _name(f.getName()), _isSigned(f.getIsSigned()), _signedGrade(f.getSignedGrade())
        , _exeGrade(f.getExeGrade())
{
    if (_signedGrade > 150 || _exeGrade > 150)
        throw (GradeTooLowException());
    else if (_signedGrade < 1 || _exeGrade < 1)
        throw (GradeTooHighException());
    std::cout << "Form(const Form& F)" << *this << std::endl;
}

Form::~Form()
{
    std::cout << "~Form()" << _name << std::endl;
}

Form::Form(const std::string name, const int sGrade, const int eGrade)
    :   _name(name), _isSigned(false), _signedGrade(sGrade), _exeGrade(eGrade)
{
    if (_signedGrade > 150 || _exeGrade > 150)
        throw (GradeTooLowException());
    else if (_signedGrade < 1 || _exeGrade < 1)
        throw (GradeTooHighException());
    
    std::cout << "Form(...)" << *this << std::endl;
}

std::string Form::getName() const
{
    return (_name);
}

bool Form::getIsSigned() const
{
    return (_isSigned);
}

int Form::getSignedGrade() const
{
    return (_signedGrade);
}

int Form::getExeGrade() const
{
    return (_exeGrade);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Higher than standard ");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Lower than standard");
}

void Form::beSigned(const Bureaucrat& b)
{
    // ?? ??? ????? ???? (?) ??? ??? ??? ???
    if (b.getGrade() > _signedGrade)
        throw (GradeTooLowException());
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, Form& b)
{
    os << b.getName() << ", " << "isSigned : " << b.getIsSigned() 
    << " signGrade : " << b.getSignedGrade() << " exeGrade : " << b.getExeGrade() << std::endl; 
    return (os);
}
