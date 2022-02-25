/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:14:11 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/25 19:16:01 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie		*zhorde;
	int			n;
	std::string	zname;

	std::cout << "Put the number of zombies: ";
	std::cin >> n;
	std::cout << "Put the zombie's name: ";
	std::cin >> zname;
	zhorde = zombieHorde(n, zname);
	delete [] zhorde;
	return (0);
}