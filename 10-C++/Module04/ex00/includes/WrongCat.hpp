/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:02:38 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 22:12:34 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
	
	public:
		WrongCat(void);
		WrongCat(WrongCat const &);
		~WrongCat(void);
		
		WrongCat& operator=(WrongCat const &);

		void	makeSound(void) const;
};