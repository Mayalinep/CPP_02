/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:44:24 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/28 12:14:21 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0) {
    std::cout << BLUE_STEEL << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& rhs) {
    std::cout << BLUE_CORNFLOVER << "Copy constructor called" << RESET << std::endl;
    *this = rhs;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
    std::cout << BLUE_LAVENDER << "Copy assignment operator called" << RESET << std::endl;
    if (this != &rhs) {
        rawBits = rhs.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << BLUE_SKY << "getRawBits member function called" << RESET << std::endl;
    return rawBits;
}

void Fixed::setRawBits(int const raw) {
    rawBits = raw;
}

Fixed::~Fixed() {
    std::cout << BLUE_FROST << "Destructor called" << RESET << std::endl;
}