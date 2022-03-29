/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:03:10 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 19:39:49 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("default") {
	std::cout << "Default RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "Name RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy) : Form(copy) {
	std::cout << "Copy RobotomyRequestForm constructor called." << std::endl;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & right) {
	this->Form::operator=(right);
	return (*this);
}

std::string	const RobotomyRequestForm::getTarget() const {
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->getSigned() == false) {
		throw RobotomyRequestForm::NotSignedException();
		return ;
	}
	if (this->getExecGrade() < executor.getGrade()) {
		throw RobotomyRequestForm::GradeTooLowException();
		return ;
	}
	
	srand(time(NULL));
	int randNb = rand() % 2;
	if (randNb)
		std::cout << "Drrrrrrr.... " << this->_target << " has been robotomized..." << std::endl;
	else
		std::cout << "....ROBOTOMY FAILED." << std::endl;
}