/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:27:59 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/23 11:38:31 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &w) : _name(n), _weapon(w) {
	std::cout << this->_name << " is created." << std::endl;
}

HumanA::~HumanA(void) {
	std::cout << this->_name << " is deleted." << std::endl;
}

void HumanA::attack(void) {
	std::cout	<< this->_name << " attacks with his "
				<< this->_weapon.getType() << std::endl;
}