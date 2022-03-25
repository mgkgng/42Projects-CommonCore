/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 01:24:48 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/25 17:12:43 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const p) {

    float   alpha = ((b.getY() - c.getY()) * (p.getX() - c.getX()) + (c.getX() - b.getX())*(p.getY() - c.getY())) / 
				((b.getY() - c.getY())*(a.getX() - c.getX()) + (c.getX() - b.getX())*(a.getY() - c.getY())); 
    float   beta = ((c.getY() - a.getY())*(p.getX() - c.getX()) + (a.getX() - c.getX())*(p.getY() - c.getY())) / 
				((b.getY() - c.getY())*(a.getX() - c.getX()) + (c.getX() - b.getX())*(a.getY() - c.getY())); 
    float   gamma = 1.0f - alpha - beta;

    if (alpha > 0 && beta > 0 && gamma > 0)
        return (true);
    else
        return (false);
    
}
