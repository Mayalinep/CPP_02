/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:46:04 by mpelage           #+#    #+#             */
/*   Updated: 2025/08/02 15:40:07 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point :: Point() : x(0), y(0) {}

Point :: Point(const float x, const float y) : x(x), y(y) {
    
}

Point :: Point(const Point &rhs) : x(rhs.getX()), y(rhs.getY()) {
    
}

Point &Point :: operator=(const Point &rhs){
    if (this != &rhs){
        const_cast<Fixed &>(this->x) = rhs.getX();
        const_cast<Fixed &>(this->y) = rhs.getY();
    }
    return (*this);
}
Fixed Point :: getX() const{
    return (this->x);
}

Fixed Point :: getY() const{
    return (this->y);
}

Point :: ~Point(){}

