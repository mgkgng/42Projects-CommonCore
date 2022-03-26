/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:22:32 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 22:56:50 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	
	public:

		FragTrap(void);
		FragTrap(std::string n);
		FragTrap(FragTrap const &);
		FragTrap& operator=(FragTrap const &);
		~FragTrap(void);

		void 	attack(const std::string &target);
		void	highFivesGuys(void);
	
};