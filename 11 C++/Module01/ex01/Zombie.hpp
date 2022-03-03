/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:12:09 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/25 19:11:44 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {

    public:

        Zombie(void);
        ~Zombie(void);

        void    announce(void) const;
        void    initialiseName(std::string zname);

    private:

        std::string name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif