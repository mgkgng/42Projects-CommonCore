/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 01:24:48 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 23:50:38 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*static float	sign(Point const a, Point const b, Point const c)
{
    return ((a.getX() - c.getX()) * (b.getY() - c.getY())
        - (b.getX() - c.getX()) * (a.getY() - c.getY()));
}*/


bool	bsp(Point const a, Point const b, Point const c, Point const p) {

    std::cout << "hey " << c.getX() << std::endl;

    /*float   alpha = ((b.getY() - c.getY()) * (p.getX() - c.getX()) + (c.getX() - b.getX())*(p.getY() - c.getY())) / 
				((b.getY() - c.getY())*(a.getX() - c.getX()) + (c.getX() - b.getX())*(a.getY() - c.getY())); 
    float   beta = ((c.getY() - a.getY())*(p.getX() - c.getX()) + (a.getX() - c.getX())*(p.getY() - c.getY())) / 
				((b.getY() - c.getY())*(a.getX() - c.getX()) + (c.getX() - b.getX())*(a.getY() - c.getY())); 
    float   gamma = 1.0f - alpha - beta;*/

    (void) p;
    (void) a;
    (void) b;
    /*std::cout << "alpha: " << alpha << " beta: " << beta << " gamma: " << gamma << std::endl;
    if (alpha > 0 && beta > 0 && gamma > 0)
        return (true);
    else*/
        return (false);
    
}
