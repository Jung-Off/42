#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat()
    : _name("NO"), _grade(1)
{
    std::cout << "Bureaucrat() " << _name << ", " << _grade << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &b)
{
    if (this != &b)
    {
        //여기 부분을 어떻게 처리를 할까!
        //const는 만들자 마자 대입을 하지 않으면 대입할 수 없음!
        // _name = B.getName();
        _grade = b.getGrade();
        (std::string&)_name = b.getName();
        std::cout << "Bureaucrat operator =" << _name << ", "<< _grade << std::endl;
    }
    return (*this);
}

//여기에 1이하 150 이상이 들어오면 만들지 말아라 라는 조건이 필요할까?
//Bureaucrat::Bureaucrat(std::string name, int grade) 여기서 다 걸리는데?
Bureaucrat::Bureaucrat(const Bureaucrat& B)
    :   _name(B.getName()), _grade(B.getGrade())
{
    if (_grade < 1)
        throw(GradeTooHighException());
    else if (_grade > 150)
        throw(GradeTooLowException()); 
    std::cout << "Bureaucrat(const Bureaucrat& B) " << _name << ", "<< _grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "~Bureaucrat() " << _name << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade)
    : _name(name), _grade(grade)
{
    if (_grade < 1)
        throw(GradeTooHighException());
    else if (_grade > 150)
        throw(GradeTooLowException());    
    std::cout << "Bureaucrat(...) " << _name << ", "<< _grade << std::endl;
}

//const std::string _name 이라서
//return std::string하면 대입이 안됨
//대입연산에서 사용하기 위함
//const를 붙인다!
std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::increGrade(int i) //(2 -> 1)
{
    if (_grade - i < 1)
        throw(GradeTooHighException());
    
    std::cout << "grade Higher " << _grade << " -> ";
    _grade -= i;
    std::cout << _grade << std::endl;
}

void Bureaucrat::decreGrade(int i) //(1 -> 2)
{
    if (_grade + i > 150)
        throw(GradeTooLowException());
    std::cout << "grade Lower " << _grade << " -> ";
    _grade += i;
    std::cout << _grade << std::endl;
}

void Bureaucrat::signForm(Form &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << "<" << _name << "> signs <" << f.getName() << ">" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "<" << _name << "> cannot sign <" << f.getName() 
        << "> because ";
        throw ;
    }    
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Too High");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Too Low");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& b)
{
    std::cout << "<" << b.getName() << ">, bureaucrat grade " << "<" << b.getGrade() << ">" << std::endl;
    return (os);
}

void Bureaucrat::executeForm(Form const & form)
{
    try
    {   
        if (!form.getIsSigned())
            throw(Form::isNotSignedException());
        form.execute(*this);
        std::cout << "Bureaucrat : [" << getName() << "] " << "is exe [" << form.getName() << "] (" <<
            form.getType() << ")" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}