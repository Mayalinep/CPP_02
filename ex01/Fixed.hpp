/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:14:31 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/31 13:23:35 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

// colors
#define BLUE_STEEL "\033[38;5;153m"
#define BLUE_CORNFLOVER "\033[38;5;30m"
#define BLUE_LAVENDER "\033[38;5;189m"
#define BLUE_SKY "\033[38;5;117m"
#define BLUE_FROST "\033[38;5;116m"
#define RESET "\033[0m"
	

class Fixed{
	private:
		int rawBits;
		static const int value_bits = 8;		




	public:
		Fixed();
		Fixed( const int raw);
		Fixed( const float raw);
		
		//copie
		Fixed( const Fixed& rhs);

		//operator
		Fixed& operator=(const Fixed& rhs);
		
		//setter
		void setRawBits(int const raw);
		//getter
		int getRawBits(void) const;

		//fonction
		float toFloat(void) const;
		int toInt(void) const;

		~Fixed();

	
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


