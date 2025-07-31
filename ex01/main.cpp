/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:21:46 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/31 13:50:39 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"



int main( void ) {
	Fixed a; //default constructor
	Fixed const b( 10 ); //constructor with rawBits at 10	
	Fixed const c( 42.42f ); //constructor with rawBits at 42.42f (float)
	Fixed const d( b );// copy constructor with Fixed b	
	
	a = Fixed( 1234.4321f ); //assignation operator with Fixed 1234.4321f
	
	std::cout << "a is " << a << std::endl; 
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	/*rawbits after conversion to fixed point
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << d.getRawBits() << std::endl;
	*/
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}


/*
 * ============================================================================
 * DÉMONSTRATION DES CONVERSIONS ET SURRECHARGES D'OPÉRATEURS
 * ============================================================================
 * 
 * Ce programme illustre l'implémentation avancée de la classe Fixed avec :
 * - Constructeurs de conversion (int → Fixed, float → Fixed)
 * - Surcharge de l'opérateur d'affichage (operator<<)
 * - Méthodes de conversion (toInt(), toFloat())
 * - Gestion de la précision avec roundf()
 * 
 * CONCEPTS CLÉS DÉMONTRÉS :
 * 
 * 1. CONVERSIONS DE TYPES :
 *    - int → Fixed : rawBits = value * 2^8 (décalage de 8 bits)
 *    - float → Fixed : rawBits = roundf(value * 2^8) (arrondi pour précision)
 *    - Fixed → int : return rawBits >> 8 (troncature de la partie fractionnaire)
 *    - Fixed → float : return rawBits / 256.0f (conversion précise)
 * 
 * 2. SURRECHARGE D'OPÉRATEURS :
 *    - operator<< : Conversion automatique Fixed → string pour affichage
 *    - operator= : Gestion de l'auto-assignation et des objets temporaires
 *    - Constructeurs de conversion : Permettent l'initialisation directe
 * 
 * 3. GESTION DE LA PRÉCISION :
 *    - Utilisation de roundf() pour minimiser les erreurs d'arrondi
 *    - Compromis entre précision et performance
 *    - Gestion des cas limites (valeurs négatives, overflow)
 * 
 * 4. CONSTRUCTEURS ET SÉMANTIQUE :
 *    - Constructeur par défaut : initialise à 0.0
 *    - Constructeur de conversion : permet Fixed(42) et Fixed(42.42f)
 *    - Constructeur de copie : 
 *    - Opérateur d'affectation : 
 * 
 * ============================================================================
 */