/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:44:15 by agautier          #+#    #+#             */
/*   Updated: 2021/11/30 00:23:06 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {
	Form form1("form1", false, 40);
	Form form2("form2", false, 42);
	Form form3("form3", false, 43);
	Form form4("form4", false);

	Bureaucrat bureaucrat("bureaucrat", 42);

	bureaucrat.signForm(form1);
	bureaucrat.signForm(form2);
	bureaucrat.signForm(form3); // Cannot be signed
	bureaucrat.signForm(form4); // Cannot be signed
	try {
		Form f_err("f_err", false, 151);
	} catch (const std::exception& e) {
		std::cerr << "Cannot create form because: " << e.what() << std::endl;
	}
}
