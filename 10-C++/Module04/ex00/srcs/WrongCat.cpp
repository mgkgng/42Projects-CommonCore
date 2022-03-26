/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:03:05 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 22:04:13 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << "Default WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src) {
	std::cout << "Copy WrongCat constructor called." << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called." <<std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const & right) {
	this->_type = right._type;
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "Cocorico" << std::endl;
}