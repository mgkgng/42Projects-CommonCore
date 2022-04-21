/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:49:40 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/21 04:19:06 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//** simple but very delicate object of comprehension here is the concept of validity. 
//** should understand completely what it does mean to remain valid, or the iterator get invalidated, etc.

#include "ft_containers.hpp"

template<typename T>
class vector {

	private:
		T					*value;
		size_t				currentSize;
		size_t				capacity;
		std::allocator<T>	Alloc;

	public:
		vector() {
			this->value = new T[1];
			this->currentSize = 0;
			this->capacity = 1;
		};
		~vector() {
			delete [] this->value;
		}
	
		vector& operator=(const vector & rhs) {
			this->value = rhs.value;
			this->currentSize = rhs.currentSize;
			this->capacity = rhs.capacity;
			//* how am i going to use std::allocator?
			return (*this);
			
		}

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
		size_t	max_size() const {
			return (std::numeric_limits<T>::max());
			//** should i protect other functions concerning this numeric limit?
		}
		size_t	capacity() const {
			return (this->capacity);
		}
		void resize(size_type count);
		void resize(size_type count, T value = T());

		bool	empty() {
			return (!this->currentSize) ? true : false;
		}
		void	shrink_to_fit() {}

		void reserve(size_type new_cap) {
			if (this->capacity >= new_cap)
				return ;
			T *newVec = new T[new_cap];
			memcpy(newVec, this->value, sizeof(T) * this->capacity);
			delete [] this->value;
			this->value = newVec;
		}

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
		
		T* data() {
			return (this->value);
		};
		const T* data() const {
			return (static_cast<const T*>(this->value);			
		}

		//** should be nice if there is something like memset or bzero

		void assign(size_type count, const T& value) {
			delete [] this->value;
			this->value = new T[count];
			for (int i = 0; i < count; i++)
				this->value[i++] = value;
			this->capacity = count;
			this->currentSize = count;

			//* either this method, either simple push_back inside a for loop
			//* but i would guess that delete (deallocation) iwould be quite necessary as it should replace the value array?
		};
		
		//** it should be not bad if i have methode from the iterator class like distance..
		template <class InputIt>
		void assign(InputIt first, InputIt last) {
			delete [] this->value;
			for (InputIt it = first; )
		}

		void	push_back(const T& value) {
			if (this->currentSize == this->capacity) {
				T	*newVector = new T[this->capacity * 2];
				for (int i = 0; i < this->capacity; i++)
					newVector[i] = value[i];
				delete [] value;
				value = newVector;
				this->capacity *= 2;
			}
			value[++(this->currentSize)] = value;
		}

		void	pop_back() {
			this->value[currentSize--] = NULL;
		}


		void	insert() {}

		iterator erase( iterator pos );
		iterator erase( iterator first, iterator last );
		
		void 	swap( vector& other ) {
			vector tmp = other;
			other = *this;
			*this = tmp;
			//* don't need to really be worried about leaks because it's only about assigning the address of memory when it comes to value array.
		} 

		void	clear() {
			//** is it enough to give NULL value to the pointer to invalidate the iterator?
			//** here i can myself use the iterator begin and end
			//** capacity shouldn't be changed
			bzero(static_cast<void *>(this->value), sizeof(T) * capacity);
			this->currentSize = 0;
		}
		void	emplace() {}
		void	emplace_back() {}



};

//* what to check? do i need a getter? vector<T> is the right form of value? maybe iterator itself should be put?

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