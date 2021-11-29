/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:54:25 by agautier          #+#    #+#             */
/*   Updated: 2021/11/30 00:38:12 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*
**	Default constructor with optionnal parameters.
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
**	Destructor.
*/
Bureaucrat::~Bureaucrat() {}

/*
**	Getter for _name.
*/
std::string const& Bureaucrat::getName() const { return (this->_name); }

/*
**	Getter for _grade.
*/
int Bureaucrat::getGrade() const { return (this->_grade); }

/*
**	Increment grade.
*/
void Bureaucrat::incrementGrade() {
	if (_grade > MAX_GRADE + 1)
		_grade--;
	else
		throw Bureaucrat::gradeTooHighException();
}

/*
**	Decrement grade.
*/
void Bureaucrat::decrementGrade() {
	if (_grade < MIN_GRADE - 1)
		_grade++;
	else
		throw Bureaucrat::gradeTooLowException();
}

void Bureaucrat::signForm(Form& form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	} catch (std::exception const& e) {
		std::cout << _name << " cannot sign " << form.getName()
				  << " because: " << e.what() << std::endl;
	}
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
	(void)rhs;
	return (*this);
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const& rhs) {
	o << rhs.getName() << ", Bureaucrat grade " << rhs.getGrade() << "."
	  << std::endl;
	return o;
}

char const* Bureaucrat::gradeTooHighException::what() const throw() {
	return ("Exception : grade is too high");
}

char const* Bureaucrat::gradeTooLowException::what() const throw() {
	return ("Exception : grade is too low");
}
