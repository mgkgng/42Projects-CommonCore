/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 00:49:08 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/30 00:50:38 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

void	to_char(void *v) {
	std::cout << "char: ";
	
	try {
		char *c = dynamic_cast<char *>(v);
	} catch (std::)
	
}

void	to_int(void *v) {

}

void	to_float(void *v) {

}

void	to_double(void *v) {

}