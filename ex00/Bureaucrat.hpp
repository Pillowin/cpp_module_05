/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:54:24 by agautier          #+#    #+#             */
/*   Updated: 2021/11/25 12:22:49 by agautier         ###   ########.fr       */
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
		Bureaucrat(const std::string& name = "default", int grade = MIN_GRADE);
		Bureaucrat(Bureaucrat& src);
		~Bureaucrat();

		const std::string& getName() const;
		int getGrade() const;

		void incGrade();
		void decGrade();

		class gradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};
		class gradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};

	private:
		const std::string _name;
		int _grade;

		Bureaucrat& operator=(const Bureaucrat& rhs);
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs);

#endif
