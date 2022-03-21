/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:28:38 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/19 18:53:16 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {

	public:
		HumanA(std::string n, Weapon &w);
		~HumanA(void);

		void attack(void);

	private:
		std::string 		_name;
		std::string const	&_weapon;
};