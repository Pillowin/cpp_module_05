/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:54:25 by agautier          #+#    #+#             */
/*   Updated: 2021/11/30 00:47:45 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
**	Default and parametric constructor.
*/
Bureaucrat::Bureaucrat(std::string const& name, int grade) :
	_name(name), _grade(grade) {
	if (_grade > MIN_GRADE)
		throw gradeTooLowException();
	if (_grade < MAX_GRADE)
		throw gradeTooHighException();
}

/*
**	Copy constructor.
*/
Bureaucrat::Bureaucrat(Bureaucrat& src) :
	_name(src._name), _grade(src._grade) {}

/*
**	Destructor.
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
**	Decrement grade.
*/
void Bureaucrat::incrementGrade(void) {
	if (_grade > MAX_GRADE + 1)
		_grade--;
	else
		throw Bureaucrat::gradeTooHighException();
}

/*
**	Increment grade.
*/
void Bureaucrat::decrementGrade(void) {
	if (_grade < MIN_GRADE - 1)
		_grade++;
	else
		throw Bureaucrat::gradeTooLowException();
}

/*
**	Private assignation operator.
*/
Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
	(void)rhs;
	return (*this);
}

/*
**	Output operator.
*/
std::ostream& operator<<(std::ostream& o, Bureaucrat const& rhs) {
	o << rhs.getName() << ", Bureaucrat grade " << rhs.getGrade() << "."
	  << std::endl;
	return o;
}

/*
**	Exception too high.
*/
char const* Bureaucrat::gradeTooHighException::what(void) const throw() {
	return ("grade is too high");
}

/*
**	Exception too low.
*/
char const* Bureaucrat::gradeTooLowException::what(void) const throw() {
	return ("grade is too low");
}
