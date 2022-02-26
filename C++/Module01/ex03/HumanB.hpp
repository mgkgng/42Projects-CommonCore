/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:33:18 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/26 11:58:33 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {

	public:
		HumanB(std::string name);
		~HumanB(void);

		void attack(void) const;
		void setWeapon(Weapon weapon);
	private:
		std::string _name;
		std::string *_weapon;
};

#endif