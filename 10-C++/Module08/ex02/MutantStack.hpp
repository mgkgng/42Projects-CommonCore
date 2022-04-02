/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 01:28:27 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/02 20:12:08 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <deque>
#include <stack>

template < typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

	using std::stack<T, Container>::c;
	public:
		MutantStack() {}
		MutantStack(MutantStack const & src) {*this = src;}
		~MutantStack() {}

		typedef typename Container::iterator		iterator;
		typedef typename Container::const_iterator	const_iterator;
		
		iterator begin() {return std::begin(c);}
		iterator end() {return std::end(c);}
		const_iterator begin() const {return std::begin(c);}
		const_iterator end() const {return std::end(c);}
		
		MutantStack& operator=(MutantStack const & right) {
			this->c = right.c;
			return (*this);
		}
};