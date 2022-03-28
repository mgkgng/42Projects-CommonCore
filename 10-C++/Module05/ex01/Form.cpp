/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:38:42 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/28 20:08:03 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("(default)") {
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
	(unsigned int) this->_signGrade = right._signGrade;
	(unsigned int) this->_executeGrade = right._executeGrade;
	return (*this);
}

std::ostream& operator<<(std::ostream& out, Form const & one) {
	out << one.getName() << ", Form grade " << one.getGrade() << ".";
	return (out);
}

std::string	const Form::getName() const {
	return (this->_name);
}

bool Form::getSigned() const {
	return (this->_signed);
}

unsigned int Form::getSignGrade() const