#ifndef ROBOTO_HPP
#define ROBOTO_HPP

#include <iostream>

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:

	public:
        RobotomyRequestForm();
        RobotomyRequestForm& operator=(const RobotomyRequestForm& s);
        RobotomyRequestForm(const RobotomyRequestForm& s);
        ~RobotomyRequestForm();

		RobotomyRequestForm(const std::string name);

		virtual void execute(Bureaucrat const& exe) const;
};

#endif