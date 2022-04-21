/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:49:40 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/21 02:26:32 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ft_containers.hpp"

template<typename T>
class vector {

	private:
		T					*value;
		size_t				currentSize;
		size_t				allocated;
		std::allocator<T>	Alloc;

	public:
		vector() {
			this->value = new T[1];
			this->currentSize = 0;
			this->allocated = 1;
		};
		~vector(
			Alloc.de
		);
	
		vector& operator=() {}

		/*// iterators
		class iterator {}
		class reverse_iterator {}

		vector<T>::iterator begin() {}
		vector<T>::iterator end() {}
		vector<T>::reverse_iterator rbegin(){}
		vector<T>::reverse_iterator rend(){}*/

		size_t	size() const {
			return (this->currentSize);
		}
		size_t	max_size() const {}
		size_t	capacity() const {
			return (this->allocated);
		}
		void	resize(int n) {}
		bool	empty() {
			return (!this->currentSize) ? true : false;
		}
		void	shrink_to_fit() {}
		void	reserve() {}

		T&	operator[](int n) {}
		T&	at(int n) {
			return (this->value[n]);
		}
		T&	front() {
			return (this->value[0]);
		}
		T&	back() {
			return (this->value[this->currentSize])
		}
		T*	data() {}

		void assign(size_type count, const T& value) {
			
		};
		
		template <class InputIt>
		void assign(InputIt first, InputIt last);

		void	push_back(const T& value) {
			if (this->currentSize == this->allocated) {
				T	*newVector = new T[this->allocated * 2];
				for (int i = 0; i < this->allocated; i++)
					newVector[i] = value[i];
				delete [] value;
				value = newVector;
				this->allocated *= 2;
			}
			value[++(this->currentSize)] = value;
		}

		void	pop_back() {
			this->value[currentSize--] = NULL;
		}

		void	insert() {}
		void	erase() {}
		void	swap() {}
		void	clear() {}
		void	emplace() {}
		void	emplace_back() {}


};

template <typename T>
bool	operator==(vector<T> lhs, vector<T> rhs) {
	
}

template <typename T>
bool	operator!=(vector<T> lhs, vector<T> rhs) {}

template <typename T>
bool	operator<(vector<T> lhs, vector<T> rhs) {}

template <typename T>
bool	operator<=(vector<T> lhs, vector<T> rhs) {}

template <typename T>
bool	operator>(vector<T> lhs, vector<T> rhs) {}

template <typename T>
bool	operator>=(vector<T> lhs, vector<T> rhs) {}

template <typename T>
bool	operator<=>(vector<T> lhs, vector<T> rhs) {}