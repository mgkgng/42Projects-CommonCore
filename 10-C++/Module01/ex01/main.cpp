/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:14:11 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/22 14:42:24 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << std::endl << "\033[1;34m** test 1 : a horde of zombies created by zombiehorde function **\033[0m" << std::endl;

	int n = 10;
	std::string zname = "Zomeo";
	Zombie	*zhorde = zombieHorde(n, zname);
	
	std::cout << std::endl << "\033[1;34m** test 2 : making the horde of zombies announce themselves by using announce function in a for-loop **\033[0m" << std::endl;
	
	int	i;
	for (i = 0; i < n; i++)
		zhorde[i].announce();

	std::cout << std::endl << "\033[1;34m** test 3 : destroying the horde of zombies by delete function **\033[0m" << std::endl;

	delete [] zhorde;

	std::cout << std::endl << "\033[1;34m** test 4 : before return, there should be no zombie left **\033[0m" << std::endl;

	std::cout << std::endl;

	return (0);
}