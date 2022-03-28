/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:42:45 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/28 18:10:36 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class	Animal {
	
	public:
		Animal(void);
		Animal(Animal const &);
		virtual ~Animal(void);
		
		Animal& operator=(Animal const &);

		virtual void	makeSound(void) const;

		std::string getType(void) const;

	protected:
		std::string	_type;

};