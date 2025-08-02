/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:45:50 by mpelage           #+#    #+#             */
/*   Updated: 2025/08/02 15:46:27 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point){

    // Determinant pour AB
    Fixed det_1 = ((b.getX() - a.getX()) * (point.getY() - a.getY())) - ((b.getY() - a.getY()) * (point.getX() - a.getX()));
    // Determinant pour BC
    Fixed det_2 = ((c.getX() - b.getX()) * (point.getY() - b.getY())) - ((c.getY() - b.getY()) * (point.getX() - b.getX()));
    // Determinant pour CA
    Fixed det_3 = ((a.getX() - c.getX()) * (point.getY() - c.getY())) - ((a.getY() - c.getY()) * (point.getX() - c.getX()));
    
 
    if (det_1 == 0 || det_2 == 0 || det_3 == 0)
        return (false);
    
    
    if ((det_1 > 0 && det_2 > 0 && det_3 > 0) || (det_1 < 0 && det_2 < 0 && det_3 < 0))
        return (true);
    
    
    return (false);
}
