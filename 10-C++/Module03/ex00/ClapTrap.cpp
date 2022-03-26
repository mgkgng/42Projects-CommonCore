/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:05:58 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 15:33:00 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("(default)"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout	<< "ClapTrap default constructor activated." << std::endl;
	std::cout	<< "ClapTrap " << this->_name << " has been created." << std::endl;
	std::cout	<< "HP[" << this->_hitPoints << "] / EP[" << this->_energyPoints
				<< "] / Attack Damage[" << this->_attackDamage << "]"
				<< std::endl;	
}

ClapTrap::ClapTrap(std::string n) : _name(n), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout	<< "ClapTrap name constructor activated." << std::endl;
	std::cout	<< "ClapTrap " << this->_name << " has been created." << std::endl;
	std::cout	<< "HP[" << this->_hitPoints << "] / EP[" << this->_energyPoints
				<< "] / Attack Damage[" << this->_attackDamage << "]"
				<< std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	*this = src;
	std::cout	<< "ClapTrap copy constructor activated." << std::endl;
	std::cout	<< "ClapTrap " << this->_name << " has been created." << std::endl;
	std::cout	<< "HP[" << this->_hitPoints << "] / EP[" << this->_energyPoints
				<< "] / Attack Damage [" << this->_attackDamage << "]"
				<< std::endl;

}

ClapTrap::~ClapTrap(void) {
	std::cout	<< "ClapTrap destructor activated." << std::endl;
	std::cout	<< "ClapTrap " << this->_name << " has been destroyed."
				<< std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target) {
	
	if (!this->_energyPoints) {
		std::cout	<< "ClapTrap " << this->_name << " needs more EP to attack." << std::endl;
		return ;
	}

	this->_energyPoints--;
	std::cout	<< "ClapTrap " << this->_name << " attacks " << target
				<< ", causing " << this->_attackDamage << " points of damage! ";
	
	if (!this->_energyPoints)
		std::cout << "(0 EP)" << std::endl;
	else
		std::cout << "(" << this->_energyPoints << " EP)" << std::endl;

}

void	ClapTrap::takeDamage(unsigned int amount) {

	if (!this->_hitPoints) {
		std::cout << "ClapTrap " << this->_name << " is already knocked out! (0 HP)" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->_name << " took damage of " << amount << "! ";

	if (this->_hitPoints > amount) {
		this->_hitPoints -= amount;
		std::cout << "(" << this->_hitPoints << " HP)" << std::endl; 
	}	
	else {
		this->_hitPoints = 0;
		std::cout << this->_name << " is knocked out! (0 HP)" << std::endl;
	}
	
}

void	ClapTrap::beRepaired(unsigned int amount) {
	
	if (!this->_energyPoints) {
		std::cout	<< "ClapTrap " << this->_name << " needs more EP to be repaired." << std::endl;
		return ;
	}

	if (this->_hitPoints == 10) {
		std::cout << "ClapTrap " << this->_name << " doesn't need any repair." << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->_name << " got repaired! ";

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
		std::cout << "0 EP)";
	else
		std::cout << this->_energyPoints << " EP)";

}