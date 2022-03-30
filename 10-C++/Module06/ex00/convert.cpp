/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 00:49:08 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/30 11:52:13 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

void	to_char(void *v) {
	
	std::cout << "char: ";
	
	char *c = static_cast<char *>(v);
	if (!isprint(*c)) {
		std::cout << "Non displayable" << std::endl;
		return ;
	}
	if (*c <= 127 && *c >= -128)
		std::cout << "'" << *c << "'" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void	to_int(void *v) {

	std::cout << "int: ";

	int	*n = static_cast<int *>(v);
	if (*n <= INT32_MAX && *n >= INT32_MIN)
		std::cout << *n << std::endl;
	else
		std::cout << "impossible" << std::endl;

}

void	to_float(void *v) {
	
	std::cout << "float: ";
	
	float *f = static_cast<float *>(v);
	std::cout << *f << std::endl;

}

void	to_double(void *v) {

	std::cout << "double: ";

	double *d = static_cast<double *>(v);
	std::cout << *d << std::endl;
}