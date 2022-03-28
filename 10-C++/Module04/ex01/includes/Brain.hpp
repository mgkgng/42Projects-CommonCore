/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:43:58 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/28 18:28:08 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class	Brain {
	
	public:
		Brain(void);
		Brain(Brain const &);
		~Brain(void);
		
		Brain& operator=(Brain const &);
		std::string const & getIdea(int index) const;

	private:
		std::string	_ideas[100];

};