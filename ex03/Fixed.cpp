/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:44:24 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/28 13:25:34 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0) {
    std::cout << BLUE_STEEL << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed( const int raw){
	std::cout << "Int constructor called" << std::endl;
	const int scale = 1 << value_bits;
	rawBits = raw * scale;
}

Fixed::Fixed( const float raw){
	std::cout << "Float constructor called" <<std::endl;
	const int scale = 1 << value_bits;
	rawBits = (int)roundf(raw * scale);
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
    return rawBits;
}

void Fixed::setRawBits(int const raw) {
    rawBits = raw;
}

//fonctions

float Fixed::toFloat(void) const{
	return (float)rawBits / (1 << value_bits);
}

int Fixed::toInt(void) const{
	return rawBits >> value_bits;
}

//operator
std::ostream& operator<<(std::ostream& os,const Fixed& fixed){
	os << fixed.toFloat();
	return os;
}
//destructor
Fixed::~Fixed() {
    std::cout << BLUE_FROST << "Destructor called" << RESET << std::endl;
}