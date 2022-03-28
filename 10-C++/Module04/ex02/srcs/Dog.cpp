/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:47:44 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/28 18:54:17 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal() {
	std::cout << "Default Dog constructor called." << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog const & src) : AAnimal(src) {
	std::cout << "Copy Dog constructor called." << std::endl;
	*this = src;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called." <<std::endl;
	delete this->_brain;
}

Dog& Dog::operator=(Dog const & right) {
	this->_type = right._type;
	delete this->_brain;
	this->_brain = new Brain(*right._brain);
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Wouf wouf" << std::endl;
}

Brain*	Dog::getBrain() const {
	return (this->_brain);
}