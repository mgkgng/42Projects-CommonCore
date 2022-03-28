/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:12:03 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/28 18:58:18 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria*	src[4];
	
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &);
		~MateriaSource(void);
		
		MateriaSource& operator=(MateriaSource const &);

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);

		void		cloneSource(MateriaSource const & copy);

};