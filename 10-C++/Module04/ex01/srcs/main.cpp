/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:39:32 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/28 18:59:56 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	
	const Animal*	meta[11];

	for (int i = 0; i < 5; i++)
		meta[i] = new Dog();

	for (int i = 5; i < 11; i++)
		meta[i] = new Cat();

	for (int i = 0; i < 11; i++)
		std::cout << meta[i]->getType() << std::endl;

	for (int i = 0; i < 11; i++)
		delete meta[i];
	
	return (0);
}