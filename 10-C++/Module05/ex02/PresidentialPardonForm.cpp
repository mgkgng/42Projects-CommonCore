/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:58:21 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 19:19:46 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("(default)") {
	std::cout << "Default PresidentialPardonForm constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "Target PresidentialPardonForm constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy) : Form(copy) {
	std::cout << "Copy PresidentialPardonForm constructor called." << std::endl;
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & right) {
	this->Form::operator=(right);
	return (*this);
}

std::string	const PresidentialPardonForm::getTarget() const {
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->getSigned() == false) {
		throw PresidentialPardonForm::NotSignedException();
		return ;
	}
	if (this->getExecGrade() < executor.getGrade()) {
		throw PresidentialPardonForm::GradeTooLowException();
		return ;
	}

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}