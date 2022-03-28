/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:22:37 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/28 19:33:46 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource(void) {
	std::cout << "Default MateriaSource constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->src[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & copy) {
	std::cout << "Copy MateriaSource constructor called." << std::endl;
	cloneSource(copy);
}

MateriaSource::~MateriaSource(void) {
	std::cout << "MateriaSource destructor called." << std::endl;

	for (int i = 0; i < 4; i++) {
		if (this->src[i])
			delete this->src[i];
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource const & right) {
	cloneSource(right);
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m) {
	int	i;
	for (i = 0; i < 4 && this->src[i]; i++);
	if (i == 4 && this->src[3])
		return ;
	if (m->getType() == "ice")
		this->src[i] = new Ice((Ice const &) m);
	else if (m->getType() == "cure")
		this->src[i] = new Cure((Cure const &) m);
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	if (type == "ice")
		return (new Ice());
	else if (type == "cure")
		return (new Cure());
	return (0);
}

void	MateriaSource::cloneSource(MateriaSource const & copy) {
	int	i;
	for (i = 0; i < 4; i++) {
		if (!copy.src[i])
			this->src[i] = NULL;
		else {
			delete this->src[i];
			this->src[i] = copy.src[i]->clone();
		}
	}
}