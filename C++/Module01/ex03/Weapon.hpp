/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:25:10 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/26 16:00:05 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Weapon {

	public:
		std::string type;

		Weapon(std::string weapon);
		~Weapon(void);

		void setType(std::string weapon);
		std::string const &getType(void);

	private:
};
