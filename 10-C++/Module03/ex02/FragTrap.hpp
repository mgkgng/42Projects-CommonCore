/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:21:09 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 20:42:25 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "main.hpp"

class FragTrap : public ClapTrap {
	
	public:

		FragTrap(void);
		FragTrap(std::string n);
		FragTrap(FragTrap const &);
		FragTrap& operator=(FragTrap const &);
		~FragTrap(void);

		void 	attack(const std::string &target);
		void	highFivesGuys(void);
	
};