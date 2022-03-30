/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:51:06 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/30 12:32:00 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(Intern const &src) {
	std::cout << "Copy Intern constructor called" << std::endl;
	*this = src;
}

Intern::~Intern(void) {
	std::cout << "Intern destructor called" << std::endl;
}

Intern & Intern::operator=(Intern const & right) {
	(void) right;
	return (*this);
}

Form*	Intern::makeForm(std::string fName, std::string target) {
	std::string fType[3] = {"shrubbery creation", "robotomy request", "president pardon"};
	
	for (int i = 0; i < 3; i++) {
		if (fName == fType[i]) {
			std::cout << "Intern creates " << fName << std::endl;
			switch (i) {
				case 0:
					return (new ShrubberyCreationForm(target));
				case 1:
					return (new RobotomyRequestForm(target));
				case 2:
					return (new PresidentialPardonForm(target));
			}
		}
	}
	throw Intern::NoFormMatch();
}