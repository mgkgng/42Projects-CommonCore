/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:44:48 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 22:25:14 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Default Animal constructor called." << std::endl;
}

Animal::Animal(Animal const & src) {
	std::cout << "Copy Animal constructor called." << std::endl;
	*this = src;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called." <<std::endl;
}

Animal& Animal::operator=(Animal const & right) {
	this->_type = right._type;
	return (*this);
}

std::string	Animal::getType(void) const {
	return (this->_type);
}

void	Animal::makeSound(void) const {
	std::cout << "...(mysterious sound)..." << std::endl;
}