/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:53:22 by agautier          #+#    #+#             */
/*   Updated: 2021/11/30 02:18:23 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
**	Default constructor.
*/
PresidentialPardonForm::PresidentialPardonForm(std::string const& target) :
	AForm("PresidentialPardon", false, 25, 5, target) {}

/*
**	Copy constructor.
*/
PresidentialPardonForm::PresidentialPardonForm(
	PresidentialPardonForm const& src) :
	AForm(src.getName(),
		  src.getIsSigned(),
		  src.getGradeToSign(),
		  src.getGradeToExec(),
		  src.getTarget()) {}

/*
**	Destructor.
*/
PresidentialPardonForm::~PresidentialPardonForm(void) {}

/*
**	Execute PresidentialPardonForm.
*/
void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > getGradeToExec())
		throw AForm::gradeTooLowException();
	else if (!getIsSigned())
		throw AForm::formUnsigned();
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox."
			  << std::endl;
}

/*
**	Private assignment operator.
*/
PresidentialPardonForm&
	PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs) {
	(void)rhs;
	return (*this);
}
