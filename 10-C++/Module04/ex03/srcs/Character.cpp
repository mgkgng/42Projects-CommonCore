/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:24:31 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/27 17:45:47 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("(default)"){
	std::cout << "Default Character constructor called." << std::endl;
}

Character::Character(std::string name) : _name(name) {
	std::cout << "Name Character constructor called." << std::endl;
}

Character::Character(Character const & copy) {
	std::cout << "Copy Character constructor called." << std::endl;
	*this = copy;
}

Character::~Character(void) {
	std::cout << "Character destructor called." << std::endl;
}

Character& Character::operator=(Character const & right) {
	this->_name = right.getName();
	this->cloneSlot(right);
	return (*this);
}

std::string const &	Character::getName(void) const {
	return (this->_name);
}

void	Character::equip(AMateria* m) {
	int	i;
	for (i = 0; this->_inventorySlot[i] && i < 4; i++);
	this->_inventorySlot[i] = m;
}

void	Character::unequip(int idx) {
	this->_inventorySlot[idx] = NULL;
}

void 	Character::use(int idx, ICharacter& target) {
	this->_inventorySlot[idx]->use(target);
}

void	Character::cloneSlot(Character const & copy) {
	int	i;
	for (i = 0; i < 4; i++) {
		delete this->_inventorySlot[i];
		this->_inventorySlot[i] = copy._inventorySlot[i]->clone();
	}
}