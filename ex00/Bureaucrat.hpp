/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:54:24 by agautier          #+#    #+#             */
/*   Updated: 2021/11/30 00:45:45 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat {
	public:
		Bureaucrat(std::string const& name = "default", int grade = MIN_GRADE);
		Bureaucrat(Bureaucrat& src);
		~Bureaucrat(void);

		std::string const& getName(void) const;
		int getGrade(void) const;

		void incrementGrade(void);
		void decrementGrade(void);

		class gradeTooHighException: public std::exception {
			public:
				char const* what(void) const throw();
		};
		class gradeTooLowException: public std::exception {
			public:
				char const* what(void) const throw();
		};

	private:
		std::string const _name;
		int _grade;

		Bureaucrat& operator=(Bureaucrat const& rhs);
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& rhs);

#endif
