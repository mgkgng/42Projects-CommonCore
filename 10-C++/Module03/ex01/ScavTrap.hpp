/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:57:46 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/25 21:38:15 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "main.hpp"

class ScavTrap : public ClapTrap {

	public:
		
		ScavTrap(void);
		ScavTrap(std::string n);
		ScavTrap(ScavTrap const &);
		ScavTrap& operator=(ScavTrap const &);
		~ScavTrap(void);

		void 	attack(const std::string &target);
		void 	takeDamage(unsigned int amount);
		void 	beRepaired(unsigned int amount);
		void	guardGate(void);

};