/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 02:23:58 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/01 16:16:15 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class Array {
	
	private:
		int	_size;
		T	*_elem;
	public:
		Array() : _size(0), _elem(NULL) {}
		Array(unsigned int n) : _size(n), _elem(new T[n]) {}
		Array(Array const & src) {*this = src;}
		~Array() {}
		
		Array&	operator=(Array const & copy) {
			this->_elem = copy._elem;
			this->_size = copy._size;
			return (*this);
		}
		
		T&	operator[](int idx) {
			if (idx < 0 || idx > this->_size - 1)
				throw Array::OutOfSize();
			return (this->_elem[idx]);
		}

		int	size() const {return (this->_size);}
		T	getElem() const {return (this->_elem);}

		class	OutOfSize : public std::exception {
			public:
				const char *what() const throw() {
					return ("Wrong index put.");
				}
		};
};