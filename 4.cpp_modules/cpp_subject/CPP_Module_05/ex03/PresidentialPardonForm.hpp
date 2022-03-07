#ifndef PRESIDENT_HPP
#define PRESIDENT_HPP

#include <iostream>

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:

	public:
        PresidentialPardonForm();
        PresidentialPardonForm& operator=(const PresidentialPardonForm& s);
        PresidentialPardonForm(const PresidentialPardonForm& s);
        ~PresidentialPardonForm();

		PresidentialPardonForm(const std::string name);

		virtual void execute(Bureaucrat const& exe) const;
};

#endif