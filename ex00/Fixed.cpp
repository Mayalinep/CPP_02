/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:44:24 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/27 20:05:09 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& rhs) {
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        rawBits = rhs.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return rawBits;
}

void Fixed::setRawBits(int const raw) {
    rawBits = raw;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}