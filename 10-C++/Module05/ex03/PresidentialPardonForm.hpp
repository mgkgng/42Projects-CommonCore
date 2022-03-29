/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:44:40 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 20:04:09 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include "Form.hpp"

class PresidentialPardonForm : public Form {

	private:
		std::string const _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string);
		PresidentialPardonForm(PresidentialPardonForm const &);
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=(PresidentialPardonForm const &);

		void execute(Bureaucrat const & executor) const;

		std::string const getTarget() const;

		Form*	newForm(std::string _target);

		class NotSignedException : public std::exception {
			public:
				const char *what() const throw() {
					return ("ERROR: NOT SIGNED");
				}
		};

};
