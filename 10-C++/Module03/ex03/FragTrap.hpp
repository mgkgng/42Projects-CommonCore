/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:22:32 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/21 22:24:05 by min-kang         ###   ########.fr       */
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

		void	highFivesGuys(void);

	private :
	
};