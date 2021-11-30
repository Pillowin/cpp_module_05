/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:18:39 by agautier          #+#    #+#             */
/*   Updated: 2021/11/30 02:16:18 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	public:
		PresidentialPardonForm(std::string const& target = "target");
		PresidentialPardonForm(PresidentialPardonForm const& src);
		virtual ~PresidentialPardonForm(void);

		void execute(Bureaucrat const& executor) const;

	private:
		PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);
};

#endif

