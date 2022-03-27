/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:16:04 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/27 12:19:43 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) {
	std::cout << "Default Cure constructor called." << std::endl;
	this->_type = "Cure";
}

Cure::Cure(Cure const & src) {
	std::cout << "Copy Cure constructor called." << std::endl;
	*this = src;
}

Cure::~Cure(void) {
	std::cout << "Cure destructor called." <<std::endl;
}

Cure& Cure::operator=(Cure const & right) {
	this->_type = right._type;
	return (*this);
}

AMateria*	Cure::clone(void) const {
	return (new Cure());
}