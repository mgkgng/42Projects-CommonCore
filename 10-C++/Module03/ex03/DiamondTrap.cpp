/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:22:40 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 00:32:02 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

DiamondTrap::DiamondTrap(void) {
	
}

DiamondTrap::DiamondTrap(std::string n) : ClapTrap(n) {
	
}

DiamondTrap::DiamondTrap(DiamondTrap const & copy) {
	
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "Destructor activated" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & right) {
	
}

void	DiamondTrap::whoAmI(void) {
	
}