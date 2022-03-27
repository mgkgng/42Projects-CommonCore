/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:07:00 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/27 12:08:57 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) {
	std::cout << "Default Materia constructor called." << std::endl;
}

AMateria::AMateria(AMateria const & src) {
	std::cout << "Copy Materia constructor called." << std::endl;
	*this = src;
}

AMateria::~AMateria(void) {
	std::cout << "Materia destructor called." <<std::endl;
}

AMateria& AMateria::operator=(AMateria const & right) {
	this->_type = right._type;
	return (*this);
}

std::string	const & AMateria::getType(void) const {
	return (this->_type);
}

void	AMateria::use(ICharacter& target) {
	
}