/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:23:50 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/26 13:08:33 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) : type(weapon) {
	std::cout << "Weapon created." << std::endl;
	return ;
}

Weapon::~Weapon(void) {
	return ;
}

std::string const&	Weapon::getType(void) {
	return (this->type);
}

void	Weapon::setType(std::string weapon) {
	this->type = weapon;
}