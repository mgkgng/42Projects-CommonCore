/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:24:00 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 18:13:10 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

FragTrap::FragTrap(void) : ClapTrap() {

	this->_name = "(default)";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap default constructor activated." << std::endl;
	std::cout	<< "FragTrap " << this->_name << " has been created." << std::endl;
	std::cout	<< "HP[" << this->_hitPoints << "] / EP[" << this->_energyPoints
				<< "] / Attack Damage[" << this->_attackDamage << "]"
				<< std::endl;	
}

FragTrap::FragTrap(std::string n) : ClapTrap(n) {
	this->_name = n;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout	<< "FragTrap name constructor activated." << std::endl;
	std::cout	<< "FragTrap " << this->_name << " has been created." << std::endl;
	std::cout	<< "HP[" << this->_hitPoints << "] / EP[" << this->_energyPoints
				<< "] / Attack Damage[" << this->_attackDamage << "]"
				<< std::endl;
}

FragTrap::FragTrap(FragTrap const & copy) : ClapTrap(copy) {
	*this = copy;
	std::cout << "FragTrap copy constructor activated" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destrcutor activiated." << std::endl;
	std::cout << "FragTrap " << this->_name << " got destroyed." << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap const & right) {
	ClapTrap::operator=(right);
	return (*this);
}

void	FragTrap::attack(const std::string &target) {
	
	if (!this->_energyPoints) {
		std::cout	<< "FragTrap " << this->_name << " needs more EP to attack." << std::endl;
		return ;
	}

	this->_energyPoints--;
	std::cout	<< "FragTrap " << this->_name << " attacks " << target
				<< ", causing " << this->_attackDamage << " points of damage! ";
	
	if (!this->_energyPoints)
		std::cout << "(0 EP)" << std::endl;
	else
		std::cout << "(" << this->_energyPoints << " EP)" << std::endl;

}

void	FragTrap::takeDamage(unsigned int amount) {

	if (!this->_hitPoints) {
		std::cout << "FragTrap " << this->_name << " is already knocked out! (0 HP)" << std::endl;
		return ;
	}

	std::cout << "FragTrap " << this->_name << " took damage of " << amount << "! ";

	if (this->_hitPoints > amount) {
		this->_hitPoints -= amount;
		std::cout << "(" << this->_hitPoints << " HP)" << std::endl; 
	}	
	else {
		this->_hitPoints = 0;
		std::cout << this->_name << " is knocked out! (0 HP)" << std::endl;
	}
	
}

void	FragTrap::beRepaired(unsigned int amount) {
	
	if (!this->_energyPoints) {
		std::cout	<< "FragTrap " << this->_name << " needs more EP to be repaired." << std::endl;
		return ;
	}

	if (this->_hitPoints == 10) {
		std::cout << "FragTrap " << this->_name << " doesn't need any repair." << std::endl;
		return ;
	}

	std::cout << "FragTrap " << this->_name << " got repaired! ";

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

void	FragTrap::highFivesGuys(void) {
	std::cout << "Hey! Give me a high five!" << std::endl;
}