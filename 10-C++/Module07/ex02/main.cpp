/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:49:27 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/01 16:17:29 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(int, char**)
{
    std::string test[] = {"VENI", "VIDI", "VICI"};
    Array<std::string> a(3);
    for (int i = 0; i < 3; i++)
        a[i] = test[i];
    for (int i = 0; i < 4; i++) {
        try {std::cout << a[i] << std::endl;}
        catch (std::exception &e) {std::cerr << e.what() << std::endl;}
    }
    std::cout << a.size() << std::endl;
}