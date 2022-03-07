#include "Intern.hpp"

int main()
{
    Intern mom;

    Bureaucrat b("bbb", 1);
    std::cout << std::endl;
    try
    {
        Form *rrf;

        std::cout << "=== robotomy ===" << std::endl;
        rrf = mom.makeForm("robotomy request", "Bender");
        b.executeForm(*rrf);
        b.signForm(*rrf);
        b.executeForm(*rrf);
        free(rrf);
        std::cout << std::endl;

        std::cout << "=== robotomy ===" << std::endl;    
        rrf = mom.makeForm("shrubbery request", "Bender");
        b.executeForm(*rrf);
        b.signForm(*rrf);
        b.executeForm(*rrf);
        std::cout << std::endl;

        std::cout << "=== presidential ===" << std::endl;    
        rrf = mom.makeForm("presidential request", "Bender");
        b.executeForm(*rrf);
        b.signForm(*rrf);
        b.executeForm(*rrf);
        std::cout << std::endl;

        std::cout << "=== error ===" << std::endl;    
        rrf = mom.makeForm("raaat", "Bender");
        b.executeForm(*rrf);
        b.signForm(*rrf);
        b.executeForm(*rrf);
        std::cout << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}