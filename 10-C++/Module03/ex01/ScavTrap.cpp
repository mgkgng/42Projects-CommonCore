/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:57:44 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/21 23:05:51 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout	<< "Default constructor activated." << std::endl;

}


ScavTrap::ScavTrap(std::string n) : ClapTrap(n) {
	this->_name = n;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout	<< "ScavTrap " << this->_name << " has been created." << std::endl;
	std::cout	<< "HP[" << this->_hitPoints << "] / EP[" << this->_energyPoints
				<< "] / Attack Damage[" << this->_attackDamage << "]"
				<< std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " got destroyed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &rhs) {
	ClapTrap::operator=(rhs);
	return (*this);
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << " has entered into Gate keeper mode!"  << std::endl;
}