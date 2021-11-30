/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:10:13 by agautier          #+#    #+#             */
/*   Updated: 2021/11/30 01:19:11 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <string>

class AForm {
	public:
		AForm(std::string name			= "name",
			  bool is_signed			= false,
			  int const grade_to_sign	= MIN_GRADE,
			  int const grade_to_exec	= MIN_GRADE,
			  std::string const& target = "target");
		AForm(AForm const& src);

		virtual ~AForm(void);

		std::string const& getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;
		std::string const& getTarget(void) const;

		virtual void execute(Bureaucrat const& executor) const = 0;
		void beSigned(Bureaucrat const& b);

		class gradeTooHighException: public std::exception {
			public:
				char const* what(void) const throw();
		};
		class gradeTooLowException: public std::exception {
			public:
				char const* what(void) const throw();
		};
		class formUnsigned: public std::exception {
			public:
				char const* what(void) const throw();
		};

	private:
		std::string const _name;
		bool _is_signed;
		int const _grade_to_sign;
		int const _grade_to_exec;
		std::string const _target;

		AForm& operator=(AForm const& rhs);
};

std::ostream& operator<<(std::ostream& o, AForm const& rhs);

#endif
