/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:57:39 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/03 13:43:32 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string n)
: _name(n), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout	<< "Default constructor activated." << std::endl;
	std::cout	<< "Claptrap " << this->_name << " has been created." << std::endl;
	std::cout	<< "HP[" << this->_hitPoints << "] / EP[" << this->_energyPoints
				<< "] / Attack Damage[" << this->_attackDamage << "]"
				<< std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	*this = src;
	std::cout	<< "Copy constructor activated." << std::endl;
	std::cout	<< "Claptrap " << this->_name << " has been created." << std::endl;
	std::cout	<< "HP[" << this->_hitPoints << "] / EP[" << this->_energyPoints
				<< "] / Attack Damage [" << this->_attackDamage << "]"
				<< std::endl;

}

ClapTrap::~ClapTrap(void) {
	std::cout	<< "Destructor activated." << std::endl;
	std::cout	<< "Claptrap " << this->_name << " has been destroyed."
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
	if (this->_energyPoints) {
		this->_energyPoints--;
		std::cout	<< "ClapTrap " << this->_name << " attacks " << target
					<< ", causing " << this->_attackDamage << " points of damage!"
					<< std::endl;
	}
	else
		std::cout	<< "ClapTrap " << this->_name << " needs more EP to attack."
					<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	this->_hitPoints += amount;
}