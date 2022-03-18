/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:53:00 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/18 15:44:27 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Zombie {

    public:
        Zombie(std::string zname);
        ~Zombie(void);

        void    announce(void) const;

    private:
        std::string name;
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);