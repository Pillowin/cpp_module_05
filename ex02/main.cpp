/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:44:15 by agautier          #+#    #+#             */
/*   Updated: 2021/11/30 01:16:34 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
	Bureaucrat bureaucrat("Bureaucrat", MAX_GRADE);
	std::cout << bureaucrat;

	Bureaucrat newbie("Newbie", MIN_GRADE);
	std::cout << newbie;

	std::cout << std::endl
			  << "Testing ShrubberyCreationForm ------------------" << std::endl
			  << std::endl;

	ShrubberyCreationForm shrubbery_creation("MyHugeGarden");
	std::cout << shrubbery_creation << std::endl;

	bureaucrat.executeForm(
		shrubbery_creation); // Execute form without signing it
	bureaucrat.signForm(shrubbery_creation);
	bureaucrat.executeForm(shrubbery_creation);

	std::cout << std::endl;

	newbie.signForm(shrubbery_creation);
	newbie.executeForm(shrubbery_creation);

	std::cout << std::endl
			  << "Testing RobotomyRequestForm --------------------" << std::endl
			  << std::endl;

	RobotomyRequestForm robotomy_request("Norminet");
	std::cout << robotomy_request << std::endl;

	bureaucrat.signForm(robotomy_request);
	bureaucrat.executeForm(robotomy_request);

	std::cout << std::endl;

	newbie.signForm(robotomy_request);
	newbie.executeForm(robotomy_request);

	std::cout << std::endl
			  << "Testing PresidentialPardonForm -----------------" << std::endl
			  << std::endl;

	PresidentialPardonForm presidential_pardon("Marvyn");
	std::cout << presidential_pardon << std::endl;

	bureaucrat.executeForm(
		presidential_pardon); // Execute form without signing it
	bureaucrat.signForm(presidential_pardon);
	bureaucrat.executeForm(presidential_pardon);

	std::cout << std::endl;

	newbie.signForm(presidential_pardon);
	newbie.executeForm(presidential_pardon);

	return (EXIT_SUCCESS);
}
