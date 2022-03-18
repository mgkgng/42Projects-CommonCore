/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:14:11 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/18 15:50:54 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int			n;
	std::string	zname;

	std::cout << "Put the number of zombies: ";
	std::cin >> n;
	std::cout << "Put the zombie's name: ";
	std::cin >> zname;

	Zombie	*zhorde = zombieHorde(n, zname);
	zhorde[0].announce();
	zhorde[n - 1].announce();
	delete [] zhorde;

	return (0);
}