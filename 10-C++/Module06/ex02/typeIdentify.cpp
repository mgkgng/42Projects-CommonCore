/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeIdentify.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:34:51 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/30 21:55:23 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typeIdentify.hpp"

Base *generate(void) {
	srand(time(NULL));
	int rNb = rand() % 3 + 1;
	if (rNb == 1) {
		return (new A());
	} else if (rNb == 2) {
		return (new B());
	} else {
		return (new C());
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