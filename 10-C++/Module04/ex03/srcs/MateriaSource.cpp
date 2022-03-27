/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:22:37 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/27 18:29:11 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	std::cout << "Default MateriaSource constructor called." << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & copy) {
	std::cout << "Copy MateriaSource constructor called." << std::endl;
	*this = copy;
}

MateriaSource::~MateriaSource(void) {
	std::cout << "MateriaSource destructor called." << std::endl;
}

MateriaSource& MateriaSource::operator=(MateriaSource const & right) {


}

void	MateriaSource::learnMateria(AMateria* m) {
	int	i;
	for (i = 0; this->src[i] && i < 4; i++);
	
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	return (type == "ice" || type == "cure") ? new AMateria(type) : 0;
}