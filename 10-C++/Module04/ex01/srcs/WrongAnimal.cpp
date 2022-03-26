/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:01:24 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 22:15:19 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "Default WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) {
	std::cout << "Copy WrongAnimal constructor called." << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called." <<std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const & right) {
	this->_type = right._type;
	return (*this);
}

std::string	WrongAnimal::getType(void) const {
	return (this->_type);
}