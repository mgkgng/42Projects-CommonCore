/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:54:04 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 16:00:00 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("(default)"), _signGrade(1){
	std::cout << "Default Form constructor called." << std::endl;
}

Form::Form(std::string name) : _name(name) {
	std::cout << "Name Form constructor called." << std::endl;
}

Form::Form(Form const & copy) {
	std::cout << "Copy Form constructor called." << std::endl;
	*this = copy;
}

Form::~Form(void) {
	std::cout << "Form destructor called." << std::endl;
}

Form& Form::operator=(Form const & right) {
	(std::string) this->_name = right._name;
	this->_signed = right._signed;
	(unsigned int &) this->_signGrade = right._signGrade;
	(unsigned int &) this->_executeGrade = right._executeGrade;
	return (*this);
}

std::ostream& operator<<(std::ostream& out, Form const & one) {
	out	<< "Form < " << one.getName() << " >, grade required to sign : " << one.getGrade() << "."
		<< ", grade required to execute: " << one.getExecuteGrade() << ", signed: ";
	if (one.getSigned())
		out << "yes";
	else
		out << "no";
	return (out);
}

void	Form::beSigned(Bureaucrat& b) {
	if (b.getGrade() <= this->_signGrade) {
		this->_signed = true;
	} else
		throw Form::GradeTooHighException();
}

std::string	const Form::getName() const {
	return (this->_name);
}

bool Form::getSigned() const {
	return (this->_signed);
}

unsigned int const Form::getSignGrade() const {
	return (this->_signGrade);
}

unsigned int const Form::getExecuteGrade() const {
	return (this->_executeGrade);
}