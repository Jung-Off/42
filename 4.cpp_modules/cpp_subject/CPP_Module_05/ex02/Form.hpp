
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <fstream>

#include "Bureaucrat.hpp"

class Bureaucrat;

# define S_SIGN 145
# define S_EXE 137

# define R_SIGN 72
# define R_EXE 45

# define P_SIGN 25
# define P_EXE 5

class Form
{
	private:
		const std::string _name;
		const std::string _type;
		bool		_isSigned;
		const int	_signedGrade;
		const int	_exeGrade;
	public:
		Form();
		Form& operator=(const Form& f);
		Form(const Form& f);
		virtual ~Form();

		Form(const std::string name, bool isSigned, const int sGrade, 
			const int eGrade, const std::string type);

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
		class isNotSignedException : public std::exception
		{
			public:
				const char * what() const throw();
		};

		void beSigned(const Bureaucrat& b);

		std::string getType() const;
		virtual void execute(Bureaucrat const& exe) const = 0;
		// virtual void execute(Bureaucrat const& exe) const;

};

std::ostream& operator<<(std::ostream& os, Form& b);

#endif