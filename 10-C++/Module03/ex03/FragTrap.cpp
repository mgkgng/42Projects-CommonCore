/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:22:34 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/21 22:23:51 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

FragTrap::FragTrap(void) {
	
}

FragTrap::FragTrap(std::string n) {
	this->_name = n;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout	<< "Default constructor activated." << std::endl;
	std::cout	<< "FragTrap " << this->_name << " has been created." << std::endl;
	std::cout	<< "HP[" << this->_hitPoints << "] / EP[" << this->_energyPoints
				<< "] / Attack Damage[" << this->_attackDamage << "]"
				<< std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "Hey! Give me a high five!" << std::endl;
}