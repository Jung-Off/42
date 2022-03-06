
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool		_isSigned;
		const int	_signedGrade;
		const int	_exeGrade;
	public:
		Form();
		Form& operator=(const Form& f);
		Form(const Form& f);
		~Form();

		Form(const std::string name, const int sGrade, const int eGrade);

		std::string getName() const;
		bool getIsSigned() const;
		int getSignedGrade() const;
		int getExeGrade() const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const throw();
		};

		void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, Form& b);

#endif