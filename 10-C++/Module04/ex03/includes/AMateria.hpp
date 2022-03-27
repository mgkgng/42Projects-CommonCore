/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:03:45 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/27 12:06:11 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class AMateria {
	
	protected:
		std::string	_type;

	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & copy);
		~AMateria(void);

		AMateria& operator=(AMateria const &);

		std::string const & getType() const;

		virtual AMateria*	clone() const = 0;
		virutal void		use(ICharacter& target);
}