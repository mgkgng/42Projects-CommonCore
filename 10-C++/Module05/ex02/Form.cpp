/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:54:04 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 19:18:33 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("(default)"), _signGrade(1), _execGrade(1) {
	std::cout << "Default Form constructor called." << std::endl;
	this->_signed = false;
}

Form::Form(std::string name, unsigned int sg, unsigned int eg) : _name(name), _signGrade(sg), _execGrade(eg) {
	std::cout << "Name Form constructor called." << std::endl;
	this->_signed = false;
}

Form::Form(Form const & copy) : _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {
	std::cout << "Copy Form constructor called." << std::endl;
	*this = copy;
}

Form::~Form(void) {
	std::cout << "Form destructor called." << std::endl;
}

Form& Form::operator=(Form const & right) {
	(std::string &) this->_name = right._name;
	this->_signed = right._signed;
	this->_signGrade = right._signGrade;
	this->_execGrade = right._execGrade;
	return (*this);
}

std::ostream& operator<<(std::ostream& out, Form const & one) {
	out	<< "Form < " << one.getName() << " >, grade required to sign : " << one.getSignGrade() << "."
		<< ", grade required to execute: " << one.getExecGrade() << ", signed: ";
	(one.getSigned()) ? out << "yes" : out << "no";
	return (out);
}

void	Form::beSigned(Bureaucrat const & b) {
	if (b.getGrade() <= this->_signGrade) {
		this->_signed = true;
	} else
		throw Form::GradeTooLowException();
}

std::string	const Form::getName() const {
	return (this->_name);
}

bool Form::getSigned() const {
	return (this->_signed);
}

unsigned int Form::getSignGrade() const {
	return (this->_signGrade);
}

unsigned int Form::getExecGrade() const {
	return (this->_execGrade);
}