/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:57:46 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 20:40:43 by min-kang         ###   ########.fr       */
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
		void	guardGate(void);

};