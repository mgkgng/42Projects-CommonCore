/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:59:43 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 18:33:04 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target("(default)"), Form("ShrubberyCreationForm", 25, 5) {
	std::cout << "Default ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _target(target), Form("ShrubberyCreationForm", 25, 5) {
	std::cout << "Target ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) : Form(copy) {
	std::cout << "Copy ShrubberyCreationForm constructor called." << std::endl;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & right) {
	this->Form::operator=(right);
	return (*this);
}

std::string const	ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (this->getSigned() == false) {
		throw ShrubberyCreationForm::NotSignedException();
		return ;
	}
	if (this->getExecGrade() < executor.getGrade()) {
		throw ShrubberyCreationForm::GradeTooLowException();
		return ;
	}
	
	std::ofstream output;
	output.open(this->_target + "_shrubbery");
	output << "          .     .  .      +     .      .          ." << std::endl;
	output << "     .       .      .     #       .           ." << std::endl;
	output << "        .      .         ###            .      .      ." << std::endl;
	output << "      .      .   '#:. .:##'##:. .:#'  .      ." << std::endl;
	output << "          .      . '####'###'####'  .' " << std::endl;
	output << "       .     '#:.    .:#'###'#:.    .:#'  .        .       ." << std::endl;
	output << "  .             '#########'#########'        .        ." << std::endl;
	output << "        .    '#:.  '####'###'####'  .:#'   .       ." << std::endl;
	output << "     .     .  '#######''##'##''#######'                  ." << std::endl;
	output << "                .'##'#####'#####'##'           .      ." << std::endl;
	output << "    .   '#:. ...  .:##'###'###'##:.  ... .:#'     ." << std::endl;
	output << "      .     '#######'##'#####'##'#######'      .     ." << std::endl;
	output << "    .    .     '#####''#######''#####'    .      ." << std::endl;
	output << "            .     '      000      '    .     ." << std::endl;
	output << "       .         .   .   000     .        .       ." << std::endl;
	output << ".. .. ..................O000O........................ ......" << std::endl;
	
}