/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 01:28:27 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/02 01:36:56 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	
	private:
		T	_v;
	
	public:
		MutantStack() {}
		MutantStack(MutantStack const & src) {*this = src;}
		~MutantStack() {}
		
		Mutant& operator={MutantStack const & right} {
			this->_v = right._v;
			return (*this);
		}

		MutantStack<T>::iterator 
};