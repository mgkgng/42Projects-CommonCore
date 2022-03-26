/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:22:38 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 22:56:37 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	
	public:
		DiamondTrap(void);
		DiamondTrap(std::string const);
		DiamondTrap(DiamondTrap const &);
		~DiamondTrap(void);

		DiamondTrap& operator=(DiamondTrap const &);

		void	attack(std::string const &target);
		void	whoAmI(void);

	private:
		std::string	_name;
};