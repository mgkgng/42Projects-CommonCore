/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:16:04 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/28 19:23:34 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
	std::cout << "Default Cure constructor called." << std::endl;
}

Cure::Cure(std::string const & type) : AMateria(type) {
	std::cout << "Type Cure constructor called." << std::endl;
}

Cure::Cure(Cure const & src) : AMateria(src) {
	std::cout << "Copy Cure constructor called." << std::endl;
}

Cure::~Cure(void) {
	std::cout << "Cure destructor called." <<std::endl;
}

Cure& Cure::operator=(Cure const & right) {
	this->_type = right._type;
	return (*this);
}

AMateria*	Cure::clone(void) const {
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}