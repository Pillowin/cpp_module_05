/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:02:35 by agautier          #+#    #+#             */
/*   Updated: 2021/12/06 13:35:25 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

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
	outfile.open(
		std::string().append(getTarget()).append("_shrubbery").c_str());
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
**	Private assignation operator.
*/
ShrubberyCreationForm&
	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs) {
	(void)rhs;
	return (*this);
}
