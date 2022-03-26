/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:47:21 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 21:57:37 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	this->_type = "Cat";
	std::cout << "Default Cat constructor called." << std::endl;
}

Cat::Cat(Cat const & src) : Animal(src) {
	std::cout << "Copy Cat constructor called." << std::endl;
	*this = src;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called." <<std::endl;
}

Cat& Cat::operator=(Cat const & right) {
	this->_type = right._type;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Miaou miaou" << std::endl;
}