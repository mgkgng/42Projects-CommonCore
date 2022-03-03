/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:39:30 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/03 16:40:34 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"


class Dog : public Animal {

	public:
		Dog(void);
		Dog(Dog const &);
		Dog &operator=(Dog const &);
		~Dog(void);

		void	makeSound(void);
};
