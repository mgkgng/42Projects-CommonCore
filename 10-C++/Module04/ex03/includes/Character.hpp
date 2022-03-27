/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:17:36 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/27 19:07:44 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
	private:
		std::string	_name;
		AMateria	*_inventorySlot[4];

	public:
		Character(void);
		Character(std::string);
		Character(Character const &);
		~Character(void);

		Character& operator=(Character const &);

		std::string const &	getName(void) const;
	
		void	equip(AMateria* m);
		void	unequip(int idx);
		void 	use(int idx, ICharacter& target);
		void	cloneSlot(Character const & copy);
};