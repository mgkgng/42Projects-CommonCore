/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:37:50 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/30 21:56:40 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typeIdentify.hpp"

int	main()
{
	Base* b1 = generate();
	identify(b1);
	std::cout << b1 << std::endl;
	delete b1;

	Base* b2 = generate();
	identify(*b2);
	std::cout << &b2 << std::endl;
	delete b2;
}