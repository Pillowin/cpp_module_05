/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:58:53 by agautier          #+#    #+#             */
/*   Updated: 2021/11/30 02:18:12 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*
**	Default constructor.
*/
Intern::Intern(void) : _form(nullptr) {}

/*
**	Copy constructor.
*/
Intern::Intern(Intern const& src) { *this = src; }

/*
**	Destructor.
*/
Intern::~Intern(void) { delete _form; }

/*
**	Create and return ShrubberyCreationForm.
*/
AForm* Intern::getShrubberyCreationForm(std::string const& target) {
	delete _form;
	_form = new ShrubberyCreationForm(target);
	return (_form);
}

/*
**	Create and return RobotomyRequestForm.
*/
AForm* Intern::getRobotomyRequestForm(std::string const& target) {
	delete _form;
	_form = new RobotomyRequestForm(target);
	return (_form);
}

/*
**	Create and return PresidentialPardonForm.
*/
AForm* Intern::getPresidentialPardonForm(std::string const& target) {
	delete _form;
	_form = new PresidentialPardonForm(target);
	return (_form);
}

/*
**	Lower string and remove allowed separators.
*/
std::string Intern::formatString(std::string formID) {
	std::string const& separators("_- ");

	for (size_t i = 0; i < formID.length(); i++)
		formID[i] = tolower(formID[i]);

	for (size_t i = 0; i < separators.length(); i++)
		while (formID.find(separators[i]) != std::string::npos)
			formID.erase(formID.find(separators[i]), 1);

	return (formID);
}

/*
**	Create asked form.
*/
AForm* Intern::makeForm(std::string const& form_name,
						std::string const& target) {
	std::string format_string;

	std::string dic_string[NB_FORM]
		= {"shrubberycreation", "robotomyrequest", "presidentialpardon"};

	AForm* (Intern::*choose_form[NB_FORM])(std::string const&)
		= {&Intern::getShrubberyCreationForm,
		   &Intern::getRobotomyRequestForm,
		   &Intern::getPresidentialPardonForm};

	format_string = formatString(form_name);

	for (int i = 0; i < NB_FORM; i++) {
		if (format_string == dic_string[i]) {
			std::cout << "Intern creates " << form_name << std::endl;
			return ((this->*choose_form[i])(target));
		}
	}
	std::cerr << form_name << ": unknow form" << std::endl;
	return (nullptr);
}

/*
**	Assignment operator.
*/
Intern& Intern::operator=(Intern const& rhs) {
	if (this == &rhs)
		return (*this);
	_form = rhs._form;
	return (*this);
}
