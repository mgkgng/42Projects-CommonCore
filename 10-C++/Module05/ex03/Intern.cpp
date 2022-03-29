/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:51:06 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 20:22:52 by min-kang         ###   ########.fr       */
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
	return (*this);
}

Form*	Intern::makeForm(std::string fName, std::string target) {
	std::string fType[3] = {"shrubbery creation", "robotomy request", "president pardon"};
	Form* *(Intern::*Intern::f[3])(std::string target) = {&Intern::makeShruberry, &Intern::makeRobotomy, &Intern::makePresident};
	
	for (int i = 0; i < 3; i++) {
		if (fName == fType[i]) {
			std::cout << "Intern creates " << fName << std::endl;
			return (this->f[3])(target);
		}
	}
}

Form*	Intern::makeShruberry(std::string target) const {
	return (new ShrubberyCreationForm(target));
}

Form*	Intern::makeRobotomy(std::string target) const {
	return (new RobotomyRequestForm(target));
}

Form*	Intern::makePresident(std::string target) const {
	return (new PresidentialPardonForm(target));
}