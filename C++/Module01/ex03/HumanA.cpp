/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:27:59 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/25 21:45:28 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) : _name(name) {
	std::cout << this->_name << "is created." << std::endl;
}

HumanA::~HumanA(void) {
	std::cout << this->_name << "is deleted." << std::endl;
}

void attack(void) const {
	std::cout	<< this->_name << "attacks with his "
				<< this->_weapon << std::endl;
}