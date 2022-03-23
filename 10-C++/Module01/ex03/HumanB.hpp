/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:33:18 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/23 10:54:39 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {

	public:
		HumanB(std::string name);
		~HumanB(void);

		void attack(void) const;
		void setWeapon(Weapon &weapon);
	private:
		std::string _name;
		Weapon		*_weapon;
};
