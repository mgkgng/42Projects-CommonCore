/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:48:01 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 18:34:00 by min-kang         ###   ########.fr       */
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

		class NotSignedException : public std::exception {
			public:
				const char *what() const throw() {
					return ("ERROR: NOT SIGNED");
				}
		};

};
