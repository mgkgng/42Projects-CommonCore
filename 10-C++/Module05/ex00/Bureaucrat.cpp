/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:01:31 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/27 20:03:58 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {
	std::cout << "Default Bureaucrat constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(unsigned int grade) : _grade(grade) {
	std::cout << "Grade Bureaucrat constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) {
	std::cout << "Copy Bureaucrat cnostructor called." << std::endl;
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & right) {
	this->_name = right._name;
	this->_grade = right._grade;
	return (*this);
}