/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:22:40 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 18:06:32 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap() {
	this->_name = "(default)";
	this->_hitPoints = 	this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_energyPoints;

	std::cout	<< "DiamondTrap " << this->_name << " has been created." << std::endl;
	std::cout	<< "HP[" << this->_hitPoints << "] / EP[" << this->_energyPoints
				<< "] / Attack Damage[" << this->_attackDamage << "]"
				<< std::endl;	
}

DiamondTrap::DiamondTrap(std::string const n) : ClapTrap(n + "_clap_name"), ScavTrap(n), FragTrap(n) {
	
	this->_name = n;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;

	std::cout	<< "DiamondTrap " << this->_name << " has been created." << std::endl;
	std::cout	<< "HP[" << this->_hitPoints << "] / EP[" << this->_energyPoints
				<< "] / Attack Damage[" << this->_attackDamage << "]"
				<< std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
	*this = copy;
	std::cout << "DiamondTrap copy constructor activated." << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor activated" << std::endl;
	std::cout << "DiamondTrap " << this->_name << " got destoryed!" << std::endl; 
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & right) {
	ClapTrap::operator=(right);
	return (*this);
}

void	DiamondTrap::attack(std::string const &target) {
	this->ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount) {

	if (!this->_hitPoints) {
		std::cout << "DiamondTrap " << this->_name << " is already knocked out! (0 HP)" << std::endl;
		return ;
	}

	std::cout << "DiamondTrap " << this->_name << " took damage of " << amount << "! ";

	if (this->_hitPoints > amount) {
		this->_hitPoints -= amount;
		std::cout << "(" << this->_hitPoints << " HP)" << std::endl; 
	}	
	else {
		this->_hitPoints = 0;
		std::cout << this->_name << " is knocked out! (0 HP)" << std::endl;
	}
	
}

void	DiamondTrap::beRepaired(unsigned int amount) {
	
	if (!this->_energyPoints) {
		std::cout	<< "DiamondTrap " << this->_name << " needs more EP to be repaired." << std::endl;
		return ;
	}

	if (this->_hitPoints == 10) {
		std::cout << "DiamondTrap " << this->_name << " doesn't need any repair." << std::endl;
		return ;
	}

	std::cout << "DiamondTrap " << this->_name << " got repaired! ";

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

void	DiamondTrap::whoAmI(void) {
	
}