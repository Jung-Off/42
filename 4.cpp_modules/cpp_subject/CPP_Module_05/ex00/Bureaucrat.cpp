#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : _name("NoName"), _grade(1)
{
    std::cout << "Bureaucrat() name : " << _name << std::endl;
}

//여기에 1이하 150 이상이 들어오면 만들지 말아라 라는 조건이 필요할까?
//Bureaucrat::Bureaucrat(std::string name, int grade) 여기서 다 걸리는데?
Bureaucrat::Bureaucrat(const Bureaucrat& B)
    : _name(B.getName()), _grade(B.getGrade())
{
    //여기부분은 과연..
    if (_grade > 150)
        throw(GradeTooLowException());
    else if (_grade < 1)
        throw(GradeTooHighException());
    std::cout << "Bureaucrat(const Bureaucrat& B) name : " << _name << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& B)
{
    if (this != &B)
    {
        //여기 부분을 어떻게 처리를 할까!
        //const는 만들자 마자 대입을 하지 않으면 대입할 수 없음!
        // _name = B.getName(); 
        (std::string &)_name = B.getName();
        _grade = B.getGrade();
        std::cout << "operator=(const Bureaucrat& B) name : " << _name << std::endl;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "~Bureaucrat() name : " << _name << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade)
    :   _name(name), _grade(grade)
{
    if (_grade > 150)
        throw(GradeTooLowException());
    else if (_grade < 1)
        throw(GradeTooHighException());
    std::cout << "Bureaucrat(std::string name, int grade)" << name << std::endl;
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

void Bureaucrat::gradeHigher(int i)
{
    
    if (_grade - i < 1)
        throw(GradeTooHighException());
    
    std::cout << "_grade Higher " << _grade << " -> ";
    _grade -= i;
    std::cout << _grade << std::endl;
}

void Bureaucrat::gradeLower(int i)
{
    if (_grade + i > 150)
        throw(GradeTooLowException());
    
    std::cout << "_grade Lower " << _grade << " -> ";
    _grade += i;
    std::cout << _grade << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("GradeTooHigh");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("GradeTooLow");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &B)
{
    os << "<" << B.getName() << ">" << ", bureaucrat grade" << " <" << B.getGrade() << ">" << std::endl;
    return (os);
}

