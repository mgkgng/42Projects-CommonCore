/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:52:58 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/18 21:38:24 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string zname) : name(zname){
	std::cout << "Zombie " << this->name << " just appeared!" << std::endl;
	return ;
}

Zombie::~Zombie(void){
	std::cout << this->name << ": Bgrrrrrrrr... (dying message)" << std::endl;
	return ;
}

void    Zombie::announce(void) const {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}