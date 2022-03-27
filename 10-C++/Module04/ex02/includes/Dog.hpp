/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:49:57 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/27 11:56:56 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	
	public:
		Dog(void);
		Dog(Dog const &);
		~Dog(void);
		
		Dog& operator=(Dog const &);

		void	makeSound(void) const;
		Brain*	getBrain(void) const;

	private:
		Brain*	_brain;
};