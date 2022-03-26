/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:22:40 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 12:36:48 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap() {
	
}

DiamondTrap::DiamondTrap(std::string const n) : ClapTrap(n + "_clap_name"), ScavTrap(n), FragTrap(n) {
	this->_hitPoints = 	this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_energyPoints;

	std::cout	<< "DiamondTrap " << this->_name << " has been created." << std::endl;
	std::cout	<< "HP[" << this->_hitPoints << "] / EP[" << this->_energyPoints
				<< "] / Attack Damage[" << this->_attackDamage << "]"
				<< std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
	std::cout << "Copy constructor activated." << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "Destructor activated" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & right) {
	ClapTrap::operator=(right);
	return (*this);
}

void	DiamondTrap::attack(std::string const &target) {
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	
}