/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:27:01 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/02 01:18:32 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <array>

class Span {

	private:
		int*			_nb;
		unsigned int	_size;
		unsigned int	_max;
		Span();
	public:
		Span(unsigned int N);
		Span(Span const & src);
		~Span();
		
		Span& operator=(Span const &);
			
		void	addNumber(int n);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		class NoFreeSpace : public std::exception {
			public:
				const char*	what() const throw() {
					return ("No free space to fill number.");
				}
		};

		class NoSpan : public std::exception {
			public:
				const char* what() const throw() {
					return ("No span can be found.");
				}
		};
};