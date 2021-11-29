/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:44:15 by agautier          #+#    #+#             */
/*   Updated: 2021/11/25 13:03:19 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
	try {
		Bureaucrat bureaucrat_min("bureaucrat_min", MIN_GRADE);
		std::cout << bureaucrat_min;
		bureaucrat_min.incGrade();
		std::cout << bureaucrat_min;

		Bureaucrat bureaucrat_err("bureaucrat_err",
								  INT_MIN); // Will throw an exception
		// Will not be executed
		std::cout << bureaucrat_err;

		Bureaucrat bureaucrat_max("bureaucrat_max", MAX_GRADE);
		std::cout << bureaucrat_max;

		bureaucrat_max.decGrade();
	} catch (const Bureaucrat::gradeTooLowException& e) {
		std::cerr << "Error: the grade is too low." << std::endl;
	} catch (const Bureaucrat::gradeTooHighException& e) {
		std::cerr << "Error: the grade is too high." << std::endl;
	}

	std::cout << std::endl
			  << "Now testing generic exception handling." << std::endl
			  << std::endl;

	try {
		Bureaucrat bureaucrat_min("bureaucrat_min", MIN_GRADE);
		std::cout << bureaucrat_min;

		Bureaucrat bureaucrat_max("bureaucrat_max", MAX_GRADE);
		std::cout << bureaucrat_max;

		bureaucrat_max.decGrade(); // Will throw an exception
		// Will not be executed
		bureaucrat_min.decGrade();
	} catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	return 0;
}
