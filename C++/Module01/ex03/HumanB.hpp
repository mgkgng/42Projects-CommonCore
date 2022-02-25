/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:33:18 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/25 21:41:02 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class HumanB {

	public:
		HumanB(std::string name);
		~HumanB(void);

		void attack(void) const;
	private:
		std::string _name;
		std::string _weapon;
};