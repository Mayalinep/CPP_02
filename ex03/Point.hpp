/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:46:07 by mpelage           #+#    #+#             */
/*   Updated: 2025/08/02 15:38:34 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point{
    private:
        const Fixed x;
        const Fixed y;


    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &rhs);
        Point &operator=(const Point &rhs);

        //getters
        Fixed getX() const;
        Fixed getY() const;
        ~Point();

};

bool bsp( Point const a, Point const b, Point const c, Point const point);