/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:57:44 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 22:53:30 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {

	this->_name = "(default)";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout	<< "ScavTrap default constructor activated." << std::endl;
}

ScavTrap::ScavTrap(std::string n) : ClapTrap(n) {

	this->_name = n;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout	<< "ScavTrap name constructor activated." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & copy) : ClapTrap(copy) {

	*this = copy;

	std::cout << "ScavTrap copy constructor activated" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor activated." << std::endl;
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

void	ScavTrap::guardGate(void) {
	std::cout << "Gate keeper mode!"  << std::endl;
}