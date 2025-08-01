/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:46:04 by mpelage           #+#    #+#             */
/*   Updated: 2025/08/01 17:54:23 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point :: Point() : x(0), y(0) {}

Point :: Point(const float x, const float y) : x(x), y(y) {
    
}

Fixed Point :: getX() const{
    return (this->x);
}

Fixed Point :: getY() const{
    return (this->y);
}

