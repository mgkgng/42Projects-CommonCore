/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:57:44 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 18:14:50 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {

	this->_name = "(default)";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout	<< "ScavTrap default constructor activated." << std::endl;
	std::cout	<< "ScavTrap " << this->_name << " has been created." << std::endl;
	std::cout	<< "HP[" << this->_hitPoints << "] / EP[" << this->_energyPoints
				<< "] / Attack Damage[" << this->_attackDamage << "]"
				<< std::endl;	
}

ScavTrap::ScavTrap(std::string n) : ClapTrap(n) {

	this->_name = n;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout	<< "ScavTrap name constructor activated." << std::endl;
	std::cout	<< "ScavTrap " << this->_name << " has been created." << std::endl;
	std::cout	<< "HP[" << this->_hitPoints << "] / EP[" << this->_energyPoints
				<< "] / Attack Damage[" << this->_attackDamage << "]"
				<< std::endl;

}

ScavTrap::ScavTrap(ScavTrap const & copy) : ClapTrap(copy) {

	*this = copy;

	std::cout << "ScavTrap copy constructor activated" << std::endl;
	std::cout	<< "ScavTrap name constructor activated." << std::endl;
	std::cout	<< "ScavTrap " << this->_name << " has been created." << std::endl;
	std::cout	<< "HP[" << this->_hitPoints << "] / EP[" << this->_energyPoints
				<< "] / Attack Damage[" << this->_attackDamage << "]"
				<< std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor activated." << std::endl;
	std::cout << "ScavTrap " << this->_name << " got destroyed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & right) {
	ClapTrap::operator=(right);
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
		std::cout << "(0 EP)" << std::endl;
	else
		std::cout << "(" << this->_energyPoints << " EP)" << std::endl;

}

void	ScavTrap::takeDamage(unsigned int amount) {

	if (!this->_hitPoints) {
		std::cout << "ScavTrap " << this->_name << " is already knocked out! (0 HP)" << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << this->_name << " took damage of " << amount << "! ";

	if (this->_hitPoints > amount) {
		this->_hitPoints -= amount;
		std::cout << "(" << this->_hitPoints << " HP)" << std::endl; 
	}	
	else {
		this->_hitPoints = 0;
		std::cout << this->_name << " is knocked out! (0 HP)" << std::endl;
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

	std::cout << "ScavTrap " << this->_name << " got repaired! ";

	if (10 - this->_hitPoints > amount) {
		this->_hitPoints += amount;
		std::cout << "(" << this->_hitPoints << " HP / "; 
	}	
	else {
		this->_hitPoints = 10;
		std::cout << "(10 HP / ";
	}

	this->_energyPoints--;
	if (!this->_energyPoints)
		std::cout << "0 EP)" << std::endl;
	else
		std::cout << this->_energyPoints << " EP)" << std::endl;

}

void	ScavTrap::guardGate(void) {
	std::cout << "Gate keeper mode!"  << std::endl;
}