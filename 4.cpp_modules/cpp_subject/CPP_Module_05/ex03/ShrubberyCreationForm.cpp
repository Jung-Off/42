
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("No", false, S_SIGN, S_EXE, "ShrubberyCreationForm")
{
    std::cout << "ShrubberyCreationForm() " << *this << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& s)
{
    if (this != &s)
    {
        Form::operator=(s);
    }
    std::cout << "ShrubberyCreationForm operator =  " << *this << std::endl;
    return(*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s)
    : Form(s.getName(), s.getIsSigned(), s.getSignedGrade(), s.getExeGrade(), s.getType())
{
    std::cout << "ShrubberyCreationForm copy  " << *this << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "~ShrubberyCreationForm() " << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name)
    : Form(name, false, S_SIGN, S_EXE, "ShrubberyCreationForm")
{
    std::cout << "ShrubberyCreationForm(name) " << *this << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& exe) const
{
    try
    {
        if (getExeGrade() < exe.getGrade())
            throw (GradeTooLowException());
        else
        {
            
            std::string	tree =	"               ,@@@@@@@,\n"
                                "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
                                "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
                                "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
                                "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
                                "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
                                "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
                                "       |o|        | |         | |\n"
                                "       |.|        | |         | |\n"
                                "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";

            std::ofstream ofile(getName() + "_shrubbery");

            ofile << tree;
            ofile.close();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << exe.getName() << " can't exe " << "[" << getType() << "] "
            << getName() << " ";
        throw;
    }
}