/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:47:21 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/28 18:20:49 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	std::cout << "Default Cat constructor called." << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const & src) : Animal(src) {
	std::cout << "Copy Cat constructor called." << std::endl;
	(*this) = src;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called." <<std::endl;
	delete this->_brain;
}

Cat& Cat::operator=(Cat const & right) {
	this->_type = right._type;
	delete this->_brain;
	this->_brain = new Brain(*right._brain);
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Miaou miaou" << std::endl;
}

Brain*	Cat::getBrain() const {
	return (this->_brain);
}