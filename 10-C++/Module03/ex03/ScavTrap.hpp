/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:22:28 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/21 22:24:31 by min-kang         ###   ########.fr       */
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
		
		void	guardGate(void);

	private:
};