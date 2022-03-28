/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:43:30 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/28 18:51:41 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Default Brain constructor called." << std::endl;
}

Brain::Brain(Brain const & src) {
	std::cout << "Copy Brain constructor called." << std::endl;
	*this = src;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called." <<std::endl;
}

Brain& Brain::operator=(Brain const & right) {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = right._ideas[i];
	return (*this);
}

std::string const & Brain::getIdea(int index) const {
	return (this->_ideas[index]);
}