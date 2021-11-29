/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:10:13 by agautier          #+#    #+#             */
/*   Updated: 2021/11/30 00:34:40 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Form {
	public:
		Form(std::string name		 = "default",
			 bool is_signed			 = false,
			 int const grade_to_sign = MIN_GRADE,
			 int const grade_to_exec = MIN_GRADE);
		Form(Form const& src);
		virtual ~Form(void);

		std::string const& getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;

		void beSigned(Bureaucrat const& b);

		class gradeTooHighException: public std::exception {
			public:
				char const* what() const throw();
		};
		class gradeTooLowException: public std::exception {
			public:
				char const* what() const throw();
		};

	private:
		std::string const _name;
		bool _is_signed;
		int const _grade_to_sign;
		int const _grade_to_exec;

		Form& operator=(Form const& rhs);
};

std::ostream& operator<<(std::ostream& o, Form const& rhs);

#endif
