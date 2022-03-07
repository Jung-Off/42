#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

    std::cout << "=== ShrubberyCreationForm ===" << std::endl;
    {
        //S_SIGN 145 ,S_EXE 137
        Bureaucrat a("aaa", 100);    //둘다
        Bureaucrat b("bbb", 140);    //실행 불가
        Bureaucrat c("ccc", 150);    //사인 불가, 실행불가
    
        ShrubberyCreationForm sForm("tree");

        //사인전 실행
        a.executeForm(sForm);
        b.executeForm(sForm);
        c.executeForm(sForm);

        std::cout << std::endl;
        //사인 하기
        try
        {
            sForm.beSigned(a);
            sForm.beSigned(b);
            sForm.beSigned(c);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << std::endl;

        //사인 후 실행
        a.executeForm(sForm);
        b.executeForm(sForm);
        c.executeForm(sForm);
        std::cout << std::endl;
    std::cout << "=== === === === ===" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== RobotomyRequestForm ===" << std::endl;
    {
        // R_SIGN 72 R_EXE 45
        Bureaucrat a("aaa", 30);    //둘다
        Bureaucrat b("bbb", 60);    //실행 불가
        Bureaucrat c("ccc", 150);    //사인 불가, 실행불가

        RobotomyRequestForm rForm("Robot");

        //사인전 실행
        a.executeForm(rForm);
        b.executeForm(rForm);
        c.executeForm(rForm);

        std::cout << std::endl;
        //사인 하기
        try
        {
            rForm.beSigned(a);
            rForm.beSigned(b);
            rForm.beSigned(c);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << std::endl;

        //사인 후 실행
        a.executeForm(rForm);
        b.executeForm(rForm);
        c.executeForm(rForm);
        std::cout << std::endl;
        std::cout << "=== === === === ===" << std::endl;

    }
    std::cout << std::endl;
    std::cout << "=== PresidentialPardonForm ===" << std::endl;
    
    {
         // P_SIGN 25 P_EXE 5
        Bureaucrat a("aaa", 3);    //둘다
        Bureaucrat b("bbb", 10);    //실행 불가
        Bureaucrat c("ccc", 150);    //사인 불가, 실행불가

        PresidentialPardonForm pForm("ppp");

        //사인전 실행
        a.executeForm(pForm);
        b.executeForm(pForm);
        c.executeForm(pForm);

        std::cout << std::endl;
        //사인 하기
        try
        {
            pForm.beSigned(a);
            pForm.beSigned(b);
            pForm.beSigned(c);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << std::endl;

        //사인 후 실행
        a.executeForm(pForm);
        b.executeForm(pForm);
        c.executeForm(pForm);
        std::cout << std::endl;
std::cout << "=== === === === ===" << std::endl;
    }
}