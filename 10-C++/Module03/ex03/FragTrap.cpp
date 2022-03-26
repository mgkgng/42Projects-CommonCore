/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:22:34 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 20:48:44 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {

	this->_name = "(default)";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap default constructor activated." << std::endl;
}

FragTrap::FragTrap(std::string n) : ClapTrap(n) {
	this->_name = n;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout	<< "FragTrap name constructor activated." << std::endl;
}

FragTrap::FragTrap(FragTrap const & copy) : ClapTrap(copy) {
	std::cout << "FragTrap copy constructor activated" << std::endl;
	*this = copy;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destrcutor activiated" << std::endl;
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

void	FragTrap::highFivesGuys(void) {
	std::cout << "Hey! Give me a high five!" << std::endl;
}