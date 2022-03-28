/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:09:54 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/28 19:24:38 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
	std::cout << "Default Ice constructor called." << std::endl;
}

Ice::Ice(std::string const & type) : AMateria(type) {
	std::cout << "Type Ice constructor called." << std::endl;
}

Ice::Ice(Ice const & src) : AMateria(src) {
	std::cout << "Copy Ice constructor called." << std::endl;
}

Ice::~Ice(void) {
	std::cout << "Ice destructor called." <<std::endl;
}

Ice& Ice::operator=(Ice const & right) {
	this->_type = right._type;
	return (*this);
}

AMateria*	Ice::clone(void) const {
	return (new Ice(*this));
}

void		Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}