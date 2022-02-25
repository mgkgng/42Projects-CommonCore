/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:25:10 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/25 21:28:50 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Weapon {
	public:
		std::string weaponType;
		Weapon(std::string weaponType);
		~Weapon(void);

		void	setType();
		std::string const &getType(void);
	private:
};