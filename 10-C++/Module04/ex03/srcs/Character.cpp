/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:24:31 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/28 19:33:41 by min-kang         ###   ########.fr       */
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
	this->_name = copy.getName();
	this->cloneSlot(copy);
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
	for (i = 0; i < 4 && this->_inventorySlot[i]; i++);
	if (i < 4 && this->_inventorySlot[3])
		return ;
	this->_inventorySlot[i] = m;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	this->_inventorySlot[idx] = NULL;
}

void 	Character::use(int idx, ICharacter& target) {
	this->_inventorySlot[idx]->use(target);
}

void	Character::cloneSlot(Character const & copy) {
	int	i;
	for (i = 0; i < 4; i++) {
		if (!copy._inventorySlot[i])
			this->_inventorySlot[i] = NULL;
		else {
			delete this->_inventorySlot[i];
			this->_inventorySlot[i] = copy._inventorySlot[i]->clone();
		}
	}
}