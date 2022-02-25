/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:28:38 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/25 21:45:56 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {

	public:
		HumanA(std::string name, Weapon weapon);
		~HumanA(void);

		void attack(void) const;
	private:
		std::string _name;
		std::string _weapon;
};