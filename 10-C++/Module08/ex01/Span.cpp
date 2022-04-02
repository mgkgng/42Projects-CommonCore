/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:03:37 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/02 17:57:30 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _nb(NULL), _size(0), _max(0) {}

Span::Span(unsigned int N) : _nb(new int[N]), _size(0), _max(N) {}

Span::Span(Span const & src) {*this = src;}

Span::~Span() {
	if (this->_size)
		delete[] this->_nb;
}

Span&	Span::operator=(Span const & right) {
	this->_nb = right._nb;
	this->_size = right._size;
	this->_max = right._max;
	return (*this);
}

void	Span::addNumber(int n) {
	if (this->_size < this->_max)
		_nb[this->_size++] = n;
	else
		throw Span::NoFreeSpace();
}

unsigned int	Span::longestSpan() {
	if (this->_size < 2)	
		throw Span::NoSpan();
	std::sort(this->_nb, this->_nb + this->_size);
	return (this->_nb[this->_size - 1] - this->_nb[0]);
}

unsigned int	Span::shortestSpan() {
	if (this->_size < 2)
		throw Span::NoSpan();
	std::sort(this->_nb, this->_nb + this->_size);
	int span[this->_size - 1];
	for (unsigned int i = 0; i < this->_size - 1; i++)
		span[i] = this->_nb[i + 1] - this->_nb[i];
	std::sort(span, span + this->_size - 1);
	return (span[0]);
}