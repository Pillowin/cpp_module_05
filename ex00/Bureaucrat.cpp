/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:54:25 by agautier          #+#    #+#             */
/*   Updated: 2021/11/25 13:00:58 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
	_name(name), _grade(grade) {
	if (_grade > MIN_GRADE)
		throw gradeTooLowException();
	if (_grade < MAX_GRADE)
		throw gradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat& src) :
	_name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat() {}

/*******************************************************/

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	(void)rhs;
	return (*this);
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs) {
	o << rhs.getName() << ", Bureaucrat grade " << rhs.getGrade() << "."
	  << std::endl;
	return o;
}

/*******************************************************/

const std::string& Bureaucrat::getName() const { return (this->_name); }

int Bureaucrat::getGrade() const { return (this->_grade); }

void Bureaucrat::incGrade() {
	if (_grade > MAX_GRADE + 1)
		_grade--;
	else
		throw Bureaucrat::gradeTooHighException();
}

void Bureaucrat::decGrade() {
	if (_grade < MIN_GRADE - 1)
		_grade++;
	else
		throw Bureaucrat::gradeTooLowException();
}

/*******************************************************/

const char* Bureaucrat::gradeTooHighException::what() const throw() {
	return ("Exception : grade is too high");
}

const char* Bureaucrat::gradeTooLowException::what() const throw() {
	return ("Exception : grade is too low");
}
