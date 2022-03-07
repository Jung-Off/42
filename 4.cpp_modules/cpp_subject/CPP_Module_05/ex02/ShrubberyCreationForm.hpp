#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include <iostream>

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:

	public:
        ShrubberyCreationForm();
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& s);
        ShrubberyCreationForm(const ShrubberyCreationForm& s);
        ~ShrubberyCreationForm();

		ShrubberyCreationForm(const std::string name);

		virtual void execute(Bureaucrat const& exe) const;
};

#endif