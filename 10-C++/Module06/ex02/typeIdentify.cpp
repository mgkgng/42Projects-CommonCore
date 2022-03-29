/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeIdentify.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:34:51 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/30 01:38:26 by min-kang         ###   ########.fr       */
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
	
}

void	identify(Base &p) {
	
}