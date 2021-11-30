/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:11:15 by agautier          #+#    #+#             */
/*   Updated: 2021/11/30 00:52:32 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
**	Default constructor.
*/
Form::Form(std::string name,
		   bool is_signed,
		   int const grade_to_sign,
		   int const grade_to_exec) :
	_name(name),
	_is_signed(is_signed), _grade_to_sign(grade_to_sign),
	_grade_to_exec(grade_to_exec) {
	if (_grade_to_exec > MIN_GRADE || _grade_to_sign > MIN_GRADE)
		throw Form::gradeTooLowException();
	else if (_grade_to_exec < MAX_GRADE || _grade_to_sign < MAX_GRADE)
		throw Form::gradeTooHighException();
}

/*
**	Copy constructor.
*/
Form::Form(Form const& src) :
	_name(src._name), _is_signed(src._is_signed),
	_grade_to_sign(src._grade_to_sign), _grade_to_exec(src._grade_to_exec) {}

/*
**	Destructor.
*/
Form::~Form(void) {}

/*
**	Getter for _name.
*/
std::string const& Form::getName(void) const { return (_name); }

/*
**	Getter for _is_signed.
*/
bool Form::getIsSigned(void) const { return (_is_signed); }

/*
**	Getter for _grade_to_sign.
*/
int Form::getGradeToSign(void) const { return (_grade_to_sign); }

/*
**	Getter for _grade_to_exec.
*/
int Form::getGradeToExec(void) const { return (_grade_to_exec); }

/*
**	Sign form.
*/
void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() < _grade_to_sign)
		throw Form::gradeTooLowException();
	else
		_is_signed = true;
}

/*
**	Private assignment operator.
*/
Form& Form::operator=(Form const& rhs) {
	(void)rhs;
	return (*this);
}

/*
**	Output operator overload.
*/
std::ostream& operator<<(std::ostream& o, const Form& rhs) {
	o << "Form " << rhs.getName() << ": grade to sign " << rhs.getGradeToSign()
	  << " | grade to exec " << rhs.getGradeToExec() << " | is signed "
	  << rhs.getIsSigned() << std::endl;
	return o;
}

/*
**	Grade too high exception.
*/
const char* Form::gradeTooHighException::what(void) const throw() {
	return ("grade is too high");
}

/*
**	Grade too low exception.
*/
const char* Form::gradeTooLowException::what(void) const throw() {
	return ("grade is too low");
}
