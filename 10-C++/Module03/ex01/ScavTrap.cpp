/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:57:44 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/25 21:42:18 by min-kang         ###   ########.fr       */
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

void	ScavTrap::attack(const std::string &target) {
	
	if (!this->_energyPoints) {
		std::cout	<< "ScavTrap " << this->_name << " needs more EP to attack." << std::endl;
		return ;
	}

	this->_energyPoints--;
	std::cout	<< "ScavTrap " << this->_name << " attacks " << target
				<< ", causing " << this->_attackDamage << " points of damage! ";
	
	if (!this->_energyPoints)
		std::cout << "ScavTrap " << this->_name << " has no more EP left.";
	else
		std::cout << "ScavTrap " << this->_name << " has now " << this->_energyPoints << " EP left." << std::endl;

}

void	ScavTrap::takeDamage(unsigned int amount) {

	if (!this->_hitPoints) {
		std::cout << "ScavTrap " << this->_name << " is already knocked out!" << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << this->_name << " took damage of " << amount << "! " << std::endl;

	if (this->_hitPoints > amount) {
		this->_hitPoints -= amount;
		std::cout << "ScavTrap " << this->_name << " has now " << this->_hitPoints << " HP left." << std::endl; 
	}	
	else {
		this->_hitPoints = 0;
		std::cout << "ScavTrap " << this->_name << " is knocked out!" << std::endl;
	}
	
}

void	ScavTrap::beRepaired(unsigned int amount) {
	
	if (!this->_energyPoints) {
		std::cout	<< "ScavTrap " << this->_name << " needs more EP to be repaired." << std::endl;
		return ;
	}

	if (this->_hitPoints == 10) {
		std::cout << "ScavTrap " << this->_name << " doesn't need any repair." << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << this->_name << " got repaired!" << std::endl;

	if (10 - this->_hitPoints > amount) {
		this->_hitPoints += amount;
		std::cout << "ScavTrap " << this->_name << " has now " << this->_hitPoints << " HP. " << std::endl; 
	}	
	else {
		this->_hitPoints = 10;
		std::cout << "ScavTrap " << this->_name << " is now in a perfect shape! " << std::endl;
	}

	if (!this->_energyPoints)
		std::cout << "ScavTrap " << this->_name << " has no more EP left." << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " has " << this->_energyPoints << " EP left.";

	std::cout << std::endl;

}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << " has entered into Gate keeper mode!"  << std::endl;
}