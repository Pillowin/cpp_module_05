/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:24:57 by agautier          #+#    #+#             */
/*   Updated: 2021/11/30 01:26:25 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm {
	public:
		ShrubberyCreationForm(std::string const& target = "target");
		ShrubberyCreationForm(ShrubberyCreationForm const& src);
		virtual ~ShrubberyCreationForm(void);

		void execute(Bureaucrat const& executor) const;

	private:
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);
};

#endif
