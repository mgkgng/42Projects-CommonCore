/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:49:57 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 22:12:20 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal {
	
	public:
		Dog(void);
		Dog(Dog const &);
		~Dog(void);
		
		Dog& operator=(Dog const &);

		void	makeSound(void) const;
};