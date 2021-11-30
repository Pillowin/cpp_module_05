/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:26:21 by agautier          #+#    #+#             */
/*   Updated: 2021/11/30 01:31:39 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
**	Default constructor.
*/
RobotomyRequestForm::RobotomyRequestForm(std::string const& target) :
	AForm("RobotomyRequest", false, 72, 45, target) {
	std::srand(std::time(nullptr));
}

/*
**	Copy constructor.
*/
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) :
	AForm(src.getName(),
		  src.getIsSigned(),
		  src.getGradeToSign(),
		  src.getGradeToExec(),
		  src.getTarget()) {}

/*
**	Destructor.
*/
RobotomyRequestForm::~RobotomyRequestForm(void) {}

/*
**	Execute RobotomyRequestForm.
*/
void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > getGradeToExec())
		throw AForm::gradeTooLowException();
	else if (!getIsSigned())
		throw AForm::formUnsigned();
	std::cout << "* some drilling noise *" << std::endl;
	if (std::rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully."
				  << std::endl;
	else
		std::cout << "Robotomize on " << getTarget() << " failed :(."
				  << std::endl;
}

/*
**	Private assignment operator.
*/
RobotomyRequestForm&
	RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs) {
	(void)rhs;
	return (*this);
}
