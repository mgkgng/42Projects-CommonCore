/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:44:59 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 20:03:42 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form {

	private:
		std::string const _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(ShrubberyCreationForm const &);
		~ShrubberyCreationForm();

		ShrubberyCreationForm& operator=(ShrubberyCreationForm const &);

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