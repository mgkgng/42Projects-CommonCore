/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:49:40 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/21 01:17:06 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ft_containers.hpp"

template<typename T>
class vector {

	private:
		T					value;
		size_t				size;
		size_t				allocated;
		std::allocator<T>	Alloc;

	public:
		vector() {
			this->size = 0;
			this->allocated = 0;
		};
		~vector(
			Alloc.de
		);
	
		vector& operator=() {}

		// iterators
		class iterator {}
		class const_iterator {}
		class reverse_iterator {}
		class const_reverse_iterator {}

		vector<T>::iterator begin() {}
		vector<T>::iterator end() {}
		vector<T>::reverse_iterator rbegin(){}
		vector<T>::reverse_iterator rend(){}
		vector<T>::const_iterator cbegin() {}
		vector<T>::const_iterator cend() {}
		vector<T>::const_reverse_iterator crbegin() {}
		vector<T>::const_reverse_iterator crend() {}

		size_t	size() const {}
		size_t	max_size() const {}
		size_t	capacity() const {}
		void	resize(int n) {}
		bool	empty() {
			return (!this->size) ? true : false;
		}
		void	shrink_to_fit() {}
		void	reserve() {}

		T&	operator[](int n) {}
		T&	at(int n) {}
		T&	front() {}
		T&	back() {}
		T*	data() {}

		void	assign() {}
		void	push_back() {}
		void	pop_back() {}
		void	insert() {}
		void	erase() {}
		void	swap() {}
		void	clear() {}
		void	emplace() {}
		void	emplace_back() {}


};

template <typename T>
bool	operator==(vector<T> left, vector<T> right) {
}

template <typename T>
bool	operator!=

template <typename T>
bool	operator<

template <typename T>
bool	operator<=

template <typename T>
bool	operator>

template <typename T>
bool	operator>=

template <typename T>
bool	operator<=>