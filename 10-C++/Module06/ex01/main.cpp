/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:19:20 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/31 16:52:29 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialization.hpp"

int	main() {
	
	Data*		a = new Data(6);
	uintptr_t	b = serialize(a);

	std::cout << a << std::endl;
	std::cout << serialize(a) << std::endl;
	std::cout << deserialize(b) << std::endl;

	delete a;
		
	return (0);
}