/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:59:43 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 02:01:31 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form() {
	std::cout << "Default ShrubberyCreationForm constructor called." << std::endl;
	this->_signGrade = 145;
	this->_executeGrade = 137;
}

/*ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : Form(name) {
	std::cout << "Name ShrubberyCreationForm constructor called." << std::endl;
}*/

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) : Form(copy) {
	std::cout << "Copy ShrubberyCreationForm constructor called." << std::endl;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & right) {
	(std::string) this->_name = right._name;
	this->_signed = right._signed;
	(unsigned int) this->_signGrade = right._signGrade;
	(unsigned int) this->_executeGrade = right._executeGrade;
	return (*this);
}