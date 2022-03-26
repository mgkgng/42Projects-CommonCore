/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:00:25 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 22:15:34 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class	WrongAnimal {
	
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &);
		~WrongAnimal(void);
		
		WrongAnimal& operator=(WrongAnimal const &);

		std::string getType(void) const;

	protected:
		std::string	_type;
};