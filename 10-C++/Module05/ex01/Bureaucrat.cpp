/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:42:22 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/28 23:15:32 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("(default)") {
	std::cout << "Default Bureaucrat constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
	std::cout << "Grade Bureaucrat constructor called." << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) {
	std::cout << "Copy Bureaucrat constructor called." << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat destructor called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & right) {
	(std::string) this->_name = right._name;
	this->_grade = right._grade;
	return (*this);
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const & one) {
	out << one.getName() << ", bureaucrat grade " << one.getGrade() << ".";
	return (out);
}

std::string	const Bureaucrat::getName(void) const {
	return (this->_name);
}

unsigned int Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void	Bureaucrat::UpGrade(void) {
	if (this->_grade == 1) {
		throw Bureaucrat::GradeTooHighException();
		return ;
	}
	this->_grade--;
}

void	Bureaucrat::DownGrade(void) {
	if (this->_grade == 150) {
		throw Bureaucrat::GradeTooLowException();
		return ;
	}
	this->_grade++;
}

void	Bureaucrat::signForm(Form& form) {
	form.beSigned(*this);
	if (this->_grade <= form.getSignGrade())
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	else
		std::cout << this->_name << " couldn't sign " << form.getName() << " because of low level" << std::endl;
}