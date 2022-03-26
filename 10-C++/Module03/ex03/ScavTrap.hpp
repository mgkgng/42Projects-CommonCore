/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:59:51 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 20:49:01 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "main.hpp"
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	public:
		
		ScavTrap(void);
		ScavTrap(std::string n);
		ScavTrap(ScavTrap const &);
		ScavTrap& operator=(ScavTrap const &);
		~ScavTrap(void);

		void 	attack(std::string const &target);
		void	guardGate(void);

};