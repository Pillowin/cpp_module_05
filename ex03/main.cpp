/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:44:15 by agautier          #+#    #+#             */
/*   Updated: 2021/11/26 18:09:39 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
	Intern intern;
	AForm* form1;
	AForm* form2;
	AForm* form_err;
	Bureaucrat bureaucrat("bureaucrat", MAX_GRADE);

	form1 = intern.makeForm("ROBOTOMY_REQUEST", "norminet");
	if (form1) {
		bureaucrat.signForm(*form1);
		bureaucrat.executeForm(*form1);
	}

	std::cout << std::endl;

	form2 = intern.makeForm("PresidentialPardon", "Intern");
	if (form2) {
		bureaucrat.signForm(*form2);
		bureaucrat.executeForm(*form2);
	}

	std::cout << std::endl;

	form_err = intern.makeForm("Unknown_form", "moon");
	if (form_err) {
		bureaucrat.signForm(*form_err);
		bureaucrat.executeForm(*form_err);
	}
	return 0;
}
