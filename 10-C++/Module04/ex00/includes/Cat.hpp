/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:48:49 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 22:12:16 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class	Cat : public Animal {
	
	public:
		Cat(void);
		Cat(Cat const &);
		~Cat(void);
		
		Cat& operator=(Cat const &);

		void	makeSound(void) const;
};