/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:14:31 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/27 17:52:18 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Fixed{
	private:
		int rawBits;
		static const int value_bits = 8;		




	public:
		Fixed();
		
		//copie
		Fixed( const Fixed& rhs);

		//operator
		Fixed& operator=(const Fixed& rhs);
		
		//setter
		void setRawBits(int const raw);
		//getter
		int getRawBits(void) const;
		
		~Fixed();

	
};


