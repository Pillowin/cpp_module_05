/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:54:25 by agautier          #+#    #+#             */
/*   Updated: 2021/11/30 01:28:39 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*
**	Default and parametric constructor.
*/
Bureaucrat::Bureaucrat(std::string const& name, int grade) :
	_name(name), _grade(grade) {
	if (_grade > MIN_GRADE)
		throw Bureaucrat::gradeTooLowException();
	if (_grade < MAX_GRADE)
		throw Bureaucrat::gradeTooHighException();
}

/*
**	Copy constructor.
*/
Bureaucrat::Bureaucrat(Bureaucrat& src) :
	_name(src._name), _grade(src._grade) {}

/*
**	Default constructor.
*/
Bureaucrat::~Bureaucrat(void) {}

/*
**	Getter for _name.
*/
std::string const& Bureaucrat::getName(void) const { return (this->_name); }

/*
**	Getter for _grade.
*/
int Bureaucrat::getGrade(void) const { return (this->_grade); }

/*
**	Increment grade.
*/
void Bureaucrat::incrementGrade(void) {
	if (_grade > MAX_GRADE + 1)
		_grade--;
	else
		throw Bureaucrat::gradeTooHighException();
}

/*
**	Decrement grade.
*/
void Bureaucrat::decrementGrade(void) {
	if (_grade < MIN_GRADE - 1)
		_grade++;
	else
		throw Bureaucrat::gradeTooLowException();
}

/*
**	Sign form.
*/
void Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	} catch (std::exception const& e) {
		std::cout << _name << " cannot sign " << form.getName() << " because "
				  << e.what() << "." << std::endl;
	}
}

/*
**	Execute form.
*/
void Bureaucrat::executeForm(AForm const& form) const {
	try {
		form.execute(*this);
		std::cout << getName() << " executes " << form.getName() << "."
				  << std::endl;
	} catch (std::exception const& e) {
		std::cout << _name << " cannot execute form because " << e.what() << "."
				  << std::endl;
	}
}

/*
**	Private asssignation operator.
*/
Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
	(void)rhs;
	return (*this);
}

/*
**	Output operator.
*/
std::ostream& operator<<(std::ostream& o, Bureaucrat const& rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "."
	  << std::endl;
	return o;
}

/*
**	Exception grade to high.
*/
char const* Bureaucrat::gradeTooHighException::what(void) const throw() {
	return ("grade is too high");
}

/*
**	Exception grade to low.
*/
char const* Bureaucrat::gradeTooLowException::what(void) const throw() {
	return ("grade is too low");
}
