/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeIdentify.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:34:51 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/31 14:39:32 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typeIdentify.hpp"

Base *generate(void) {
	switch (rand() % 3) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

void	identify(Base *p) {
	A* a;
	a = dynamic_cast<A*>(p);
	if (a) {
		std::cout << "AAAAA*" << std::endl;
		return ;
	}
	B* b;
	b = dynamic_cast<B*>(p);
	if (b) {
		std::cout << "BBBBB*" << std::endl;
		return ;
	}
	C* c;
	c = dynamic_cast<C*>(p);
	if (c) {
		std::cout << "CCCCC*" << std::endl;
		return ;
	}
}

void	identify(Base &p) {
	try {
		A& a= dynamic_cast<A&>(p);
		(void) a;
		std::cout << "AAAAA&" << std::endl;
		return ;
	} catch (std::bad_cast &bc) {
	}
	try {
		B& b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "BBBBB&" << std::endl;
		return ;
	} catch (std::bad_cast &bc) {
	}
	try {
		C& c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "CCCCC&" << std::endl;
		return ;
	} catch (std::bad_cast &bc) {
	}
}