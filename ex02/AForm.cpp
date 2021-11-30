/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:11:15 by agautier          #+#    #+#             */
/*   Updated: 2021/11/30 01:30:34 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*
**	Default constructor.
*/
AForm::AForm(std::string name,
			 bool is_signed,
			 int const grade_to_sign,
			 int const grade_to_exec,
			 std::string const& target) :
	_name(name),
	_is_signed(is_signed), _grade_to_sign(grade_to_sign),
	_grade_to_exec(grade_to_exec), _target(target) {
	if (_grade_to_exec > MIN_GRADE || _grade_to_sign > MIN_GRADE)
		throw AForm::gradeTooLowException();
	else if (_grade_to_exec < MAX_GRADE || _grade_to_sign < MAX_GRADE)
		throw AForm::gradeTooHighException();
}

/*
**	Copy constructor.
*/
AForm::AForm(AForm const& src) :
	_name(src._name), _is_signed(src._is_signed),
	_grade_to_sign(src._grade_to_sign), _grade_to_exec(src._grade_to_exec),
	_target(src._target) {}

/*
**	Destructor.
*/
AForm::~AForm(void) {}

/*
**	Getter for _name.
*/
std::string const& AForm::getName(void) const { return (_name); }

/*
**	Getter for _is_signed.
*/
bool AForm::getIsSigned(void) const { return (_is_signed); }

/*
**	Getter for _grade_to_sign.
*/
int AForm::getGradeToSign(void) const { return (_grade_to_sign); }

/*
**	Getter for _grade_to_exec.
*/
int AForm::getGradeToExec(void) const { return (_grade_to_exec); }

/*
**	Getter for _target.
*/
std::string const& AForm::getTarget(void) const { return (_target); }

/*
**	Sign form.
*/
void AForm::beSigned(Bureaucrat const& b) {
	if (b.getGrade() > _grade_to_sign)
		throw AForm::gradeTooLowException();
	else
		_is_signed = true;
}

/*
**	Private assignment operator.
*/
AForm& AForm::operator=(AForm const& rhs) {
	(void)rhs;
	return (*this);
}

/*
**	Output operator.
*/
std::ostream& operator<<(std::ostream& o, AForm const& rhs) {
	o << "AForm " << rhs.getName() << ": grade to sign " << rhs.getGradeToSign()
	  << " | grade to exec " << rhs.getGradeToExec() << " | is signed "
	  << rhs.getIsSigned() << " | target " << rhs.getTarget() << std::endl;
	return o;
}

/*
**	Exception grade too high.
*/
char const* AForm::gradeTooHighException::what(void) const throw() {
	return ("grade is too high");
}

/*
**	Exception grade too low.
*/
char const* AForm::gradeTooLowException::what(void) const throw() {
	return ("grade is too low");
}

/*
**	Exception form not signed.
*/
char const* AForm::formUnsigned::what(void) const throw() {
	return ("unsigned form can't be executed");
}
