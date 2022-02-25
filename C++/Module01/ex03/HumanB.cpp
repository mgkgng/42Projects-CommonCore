/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:33:42 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/25 21:42:20 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	std::cout << this->_name << "is created." << std::endl;
}

HuamnB::~HumanB(void) {
	std::cout << this->_name << "is deleted." << std::endl;
}

void attack(void) const {
	std::cout	<< this->_name << "attacks with his "
				<< this->_weapon << std::endl;
}