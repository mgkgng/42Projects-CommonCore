/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:27:01 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/01 18:31:33 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>

class Span {

	private:
		int	nb[];
		Span() {}
	public:
		Span(unsigned int N);
		Span(Span const & src);
		~Span() {}
		
		Span& operator=(Span const &);
		
		
		void	addNumber();
};