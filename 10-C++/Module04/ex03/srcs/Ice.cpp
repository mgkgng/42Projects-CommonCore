/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:09:54 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/27 12:18:54 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) {
	std::cout << "Default Ice constructor called." << std::endl;
	this->_type = "ice";
}

Ice::Ice(Ice const & src) {
	std::cout << "Copy Ice constructor called." << std::endl;
	*this = src;
}

Ice::~Ice(void) {
	std::cout << "Ice destructor called." <<std::endl;
}

Ice& Ice::operator=(Ice const & right) {
	this->_type = right._type;
	return (*this);
}

AMateria*	Ice::clone(void) const {
	return (new Ice());
}