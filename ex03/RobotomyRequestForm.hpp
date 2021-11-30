/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:26:31 by agautier          #+#    #+#             */
/*   Updated: 2021/11/30 02:16:04 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	public:
		RobotomyRequestForm(std::string const& target = "target");
		RobotomyRequestForm(RobotomyRequestForm const& src);
		virtual ~RobotomyRequestForm(void);

		void execute(Bureaucrat const& executor) const;

	private:
		RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);
};

#endif

