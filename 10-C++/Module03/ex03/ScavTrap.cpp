/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:22:30 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/21 22:24:25 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

ScavTrap::~ScavTrap() {
	
}

ScavTrap::ScavTrap(std::string n) {
	this->_name = n;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout	<< "Default constructor activated." << std::endl;
	std::cout	<< "ScavTrap " << this->_name << " has been created." << std::endl;
	std::cout	<< "HP[" << this->_hitPoints << "] / EP[" << this->_energyPoints
				<< "] / Attack Damage[" << this->_attackDamage << "]"
				<< std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << " has entered into Gate keeper mode!"  << std::endl;
}