/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:39:25 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/03 16:40:42 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal {

	public:
		Cat(void);
		Cat(Cat const &);
		Cat &operator=(Cat const &);
		~Cat(void);

		void	makeSound(void);
};