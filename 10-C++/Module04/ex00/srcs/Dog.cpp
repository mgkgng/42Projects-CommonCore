/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:47:44 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 21:58:16 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	this->_type = "Dog";
	std::cout << "Default Dog constructor called." << std::endl;
}

Dog::Dog(Dog const & src) : Animal(src) {
	std::cout << "Copy Dog constructor called." << std::endl;
	*this = src;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called." <<std::endl;
}

Dog& Dog::operator=(Dog const & right) {
	this->_type = right._type;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Wouf wouf" << std::endl;
}