/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:46:23 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/30 12:27:57 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(Intern const &);
		~Intern();

		Intern& operator=(Intern const &);

		Form*	makeForm(std::string fName, std::string target);

		class NoFormMatch : public std::exception {
			public:
				const char *what() const throw() {
					return ("DOES NOT MATCH THE NAME FORM");
				}
		};
};