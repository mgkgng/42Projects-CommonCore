/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:09:57 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/27 12:18:45 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
	
	public:
		Ice(void);
		Ice(std::string const & type);
		Ice(Ice const & copy);
		~Ice(void);

		Ice& operator=(Ice const &);

		AMateria*	clone(void) const;
		void		use(ICharacter& target);
}