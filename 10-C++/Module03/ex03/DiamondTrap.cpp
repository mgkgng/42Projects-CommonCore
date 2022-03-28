/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:22:40 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/28 14:04:09 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("(default)_clap_name"), ScavTrap(), FragTrap() {
	this->_name = "(default)";
	ClapTrap::_name = "(default)_clap_name"; 
	this->_hitPoints = 	100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;

	std::cout	<< "DiamondTrap default constructor activated." << std::endl;
}

DiamondTrap::DiamondTrap(std::string const n) : ClapTrap(n + "_clap_name"), ScavTrap(n), FragTrap(n) {
	
	this->_name = n;
	ClapTrap::_name = n + "_clap_name";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;

	std::cout	<< "DiamondTrap name constructor activated." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
	*this = copy;
	std::cout << "DiamondTrap copy constructor activated." << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor activated" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & right) {
	ClapTrap::operator=(right);
	return (*this);
}

void	DiamondTrap::attack(std::string const &target) {
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "WE ARE DIAMOND " << this->_name << " AND CLAP " << ClapTrap::_name << "!!!" << std::endl;
}