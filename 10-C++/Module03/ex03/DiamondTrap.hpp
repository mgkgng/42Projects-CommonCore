/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:22:38 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 00:27:55 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	
	public:
		DiamondTrap(void);
		DiamondTrap(std::string);
		DiamondTrap(DiamondTrap const &);
		~DiamondTrap(void);

		DiamondTrap& operator=(DiamondTrap const &);

		void	whoAmI(void);

	private:
		std::string	_name;
		
};