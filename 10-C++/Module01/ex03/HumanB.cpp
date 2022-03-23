/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:33:42 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/23 11:51:22 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	std::cout << this->_name << " is created." << std::endl;
	this->_weapon = NULL;
}

HumanB::~HumanB(void) {
	std::cout << this->_name << " is deleted." << std::endl;
}

void	HumanB::attack(void) const {
	if (this->_weapon) 
		std::cout	<< this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
	else
		std::cout	<< this->_name << " has no weapon !" << std::endl;
}

void	HumanB::setWeapon(Weapon& w) {
	this->_weapon = &w;
}

void	HumanB::disarm(void) {
	this->_weapon = NULL;
}