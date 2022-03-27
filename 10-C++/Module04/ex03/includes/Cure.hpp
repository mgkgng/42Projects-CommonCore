/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:12:54 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/27 19:01:03 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {
	
	public:
		Cure(void);
		Cure(std::string const & type);
		Cure(Cure const & copy);
		~Cure(void);

		Cure& operator=(Cure const &);

		AMateria*	clone() const;
		void		use(ICharacter& target);
};