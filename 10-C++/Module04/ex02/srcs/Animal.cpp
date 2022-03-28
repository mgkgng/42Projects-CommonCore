/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:44:48 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/28 18:55:54 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) {
	std::cout << "Default Animal constructor called." << std::endl;
}

AAnimal::AAnimal(AAnimal const & src) {
	std::cout << "Copy Animal constructor called." << std::endl;
	*this = src;
}

AAnimal::~AAnimal(void) {
	std::cout << "Animal destructor called." <<std::endl;
}

AAnimal& AAnimal::operator=(AAnimal const & right) {
	this->_type = right._type;
	return (*this);
}

std::string	AAnimal::getType(void) const {
	return (this->_type);
}