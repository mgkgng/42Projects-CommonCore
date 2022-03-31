/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:37:50 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/31 14:41:34 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typeIdentify.hpp"

int	main()
{
	srand(time(NULL));

	Base* b1 = generate();
	identify(b1);
	std::cout << b1 << std::endl;

	Base* b2 = generate();
	identify(*b2);
	std::cout << &b2 << std::endl;

	delete b1;
	delete b2;
}