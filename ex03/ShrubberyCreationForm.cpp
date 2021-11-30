/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:02:35 by agautier          #+#    #+#             */
/*   Updated: 2021/11/30 02:15:46 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

/*
**	Default constructor.
*/
ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) :
	AForm("ShrubberyCreation", false, 145, 137, target) {}

/*
**	Copy constructor.
*/
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) :
	AForm(src.getName(),
		  src.getIsSigned(),
		  src.getGradeToSign(),
		  src.getGradeToExec(),
		  src.getTarget()) {}

/*
**	Destructor.
*/
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

/*
**	Execute ShrubberyCreationForm.
*/
void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > getGradeToExec())
		throw AForm::gradeTooLowException();
	else if (!getIsSigned())
		throw AForm::formUnsigned();

	std::ofstream outfile;

	outfile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	outfile.open(getTarget() + "_shrubbery");
	outfile << "           &&& &&  & &&" << std::endl
			<< "      && &\\/&\\|& ()|/ @, &&" << std::endl
			<< "      &\\/(/&/&||/& /_/)_&/_&" << std::endl
			<< "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl
			<< "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl
			<< "&&   && & &| &| /& & % ()& /&&" << std::endl
			<< " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl
			<< "     &&     \\|||" << std::endl
			<< "             |||" << std::endl
			<< "             |||" << std::endl
			<< "             |||" << std::endl
			<< "       , -=-~  .-^- _" << std::endl
			<< "              `" << std::endl;
}

/*
**	Private assignment operator.
*/
ShrubberyCreationForm&
	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs) {
	(void)rhs;
	return (*this);
}
