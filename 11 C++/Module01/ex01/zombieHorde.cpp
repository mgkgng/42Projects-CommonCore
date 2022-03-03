/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:12:34 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/25 19:12:57 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	Zombie	*zhorde = new Zombie[N];
	int	i;
	for (i = 0; i < N; i++)
		zhorde[i].initialiseName(name);
	return (zhorde);
}