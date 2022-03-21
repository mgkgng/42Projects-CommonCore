/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:17:02 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/19 12:51:42 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {
	std::cout << "A zombie just gets created!" << std::endl;
	return ;
}

Zombie::~Zombie(void){
	std::cout << this->name << ": Bgrrrrrrrr... (dying message)" << std::endl;
	return ;
}

void    Zombie::announce(void) const {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::initialiseName(std::string zname) {
	this->name = zname;
	std::cout << zname << ": I got my name Zzzzzzzzzzz..." << std::endl;
}