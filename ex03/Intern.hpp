/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:58:52 by agautier          #+#    #+#             */
/*   Updated: 2021/11/30 02:06:18 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define NB_FORM 3

class Intern {
	public:
		Intern(void);
		Intern(Intern const& src);

		virtual ~Intern(void);

		AForm* makeForm(std::string const& form_name,
						std::string const& target);

		Intern& operator=(Intern const& rhs);

	private:
		AForm* _form;

		AForm* getShrubberyCreationForm(std::string const& target);
		AForm* getRobotomyRequestForm(std::string const& target);
		AForm* getPresidentialPardonForm(std::string const& target);

		std::string formatString(std::string formID);
};

#endif

