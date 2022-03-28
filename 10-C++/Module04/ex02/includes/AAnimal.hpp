/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:42:45 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/28 19:09:14 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class	AAnimal {
	
	public:
		AAnimal(void);
		AAnimal(AAnimal const &);
		virtual ~AAnimal(void);
		
		AAnimal& operator=(AAnimal const &);

		virtual void	makeSound(void) const = 0;

		std::string getType(void) const;

	protected:
		std::string	_type;
};