/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:44:24 by mpelage           #+#    #+#             */
/*   Updated: 2025/08/01 16:35:12 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//constructors
Fixed::Fixed() : rawBits(0) {
    //std::cout << BLUE_STEEL << "Default constructor called" << RESET << std::endl;
}

//constructors with int and float
Fixed::Fixed( const int raw){
	//std::cout << "Int constructor called" << std::endl;
	const int scale = 1 << value_bits;
	rawBits = raw * scale;
}

Fixed::Fixed( const float raw){
	//std::cout << "Float constructor called" <<std::endl;
	const int scale = 1 << value_bits;
	rawBits = (int)roundf(raw * scale);
}

//copy constructor
Fixed::Fixed(const Fixed& rhs) {
    //std::cout << BLUE_CORNFLOVER << "Copy constructor called" << RESET << std::endl;
    *this = rhs;
}

//copy assignment operator
Fixed& Fixed::operator=(const Fixed& rhs) {
    //std::cout << BLUE_LAVENDER << "Copy assignment operator called" << RESET << std::endl;
    if (this != &rhs) {
        rawBits = rhs.getRawBits();
    }
    return *this;
}

//operator <, >, <=, >=, ==, !=
bool Fixed::operator<(const Fixed& rhs) const {
	return rawBits < rhs.getRawBits();
}
bool Fixed::operator>(const Fixed& rhs) const{
	return rawBits > rhs.getRawBits();
}
bool Fixed::operator<=(const Fixed& rhs) const{
	return rawBits <= rhs.getRawBits();
}
bool Fixed::operator>=(const Fixed& rhs) const{
	return rawBits >= rhs.getRawBits();
}
bool Fixed::operator==(const Fixed& rhs) const{
	return rawBits == rhs.getRawBits();
}
bool Fixed::operator!=(const Fixed& rhs) const{
	return rawBits != rhs.getRawBits();
}

//operator +, -, *, /
Fixed Fixed::operator+(const Fixed& rhs) const{
	Fixed result;
	result.setRawBits(rawBits + rhs.getRawBits());
	return result;
}
Fixed Fixed::operator-(const Fixed& rhs) const{
	Fixed result;
	result.setRawBits(rawBits - rhs.getRawBits());
	return result;
}
Fixed Fixed::operator*(const Fixed& rhs) const{
	Fixed result;
	result.setRawBits((rawBits * rhs.getRawBits()) / (1 << value_bits));
	return result;
}
Fixed Fixed::operator/(const Fixed& rhs) const{
	Fixed result;
	result.setRawBits((rawBits / rhs.getRawBits()) / (1 << value_bits));
	return result;
}

//operator ++, --, ++(int), --(int)
Fixed& Fixed::operator++(){
	rawBits++;
	return *this;
}
Fixed& Fixed::operator--(){
	rawBits--;
	return *this;
}
Fixed Fixed::operator++(int){
	Fixed tmp = *this;
	rawBits++;
	return tmp;
}

Fixed Fixed::operator--(int){
	Fixed tmp = *this;
	rawBits--;
	return tmp;
}
	
//getRawBits
int Fixed::getRawBits(void) const {
    return rawBits;
}

//setRawBits
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

//max and min
Fixed& Fixed::max(Fixed& a, Fixed& b){
	if (a > b)
		return a;
	return b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	if (a < b)
		return a;
	return b;
}

//operator
std::ostream& operator<<(std::ostream& os,const Fixed& fixed){
	os << fixed.toFloat();
	return os;
}
//destructor
Fixed::~Fixed() {
    //std::cout << BLUE_FROST << "Destructor called" << RESET << std::endl;
}