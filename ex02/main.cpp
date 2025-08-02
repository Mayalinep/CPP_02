/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:19:56 by mpelage           #+#    #+#             */
/*   Updated: 2025/08/02 21:50:08 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
    
	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
    // std::cout << Fixed::min(a, b ) << std::endl;
    //std::cout << " b est il plus grand que a ? " << (b > a) << std::endl;
	// std::cout << --a << std::endl;
	// std::cout << ++a<< std::endl;
	// std::cout << a-- << std::endl;
	// std::cout << a << std::endl;
	return 0;
}


/*
 * ============================================================================
 * DÉMONSTRATION DES OPÉRATEURS ARITHMÉTIQUES ET DE SURRECHARGE
 * ============================================================================
 * Etapes:
  - Création d'un objet Fixed avec constructeur par défaut (valeur 0.0)
  - Test de la multiplication Fixed * Fixed (5.05 * 2 = 10.1)
  - Affichage initiale de la valeur initiale via operator<< (utilise toFloat())
  - Test de la pré-incrémentation (++a), rawBits passe de 0 à 1, affiche 1/256 = 0.00390625
  - Test de la post-incrémentation (a++), affiche 0.00390625 puis incrémente rawBits à 2, affiche 2/256 = 0.0078125
  - Test de la fonction statique max (retourne le plus grand des deux)

  
 * Ce programme illustre l'implémentation complète de la classe Fixed avec :
 * - Opérateurs de comparaison (>, <, >=, <=, ==, !=)
 * - Opérateurs arithmétiques (+, -, *, /)
 * - Opérateurs d'incrémentation/décrémentation (++, --, ++(int), --(int))
 * - Fonctions statiques min/max avec surcharge const/non-const
 * 
 * CONCEPTS CLÉS DÉMONTRÉS :
 * 
 * 1. OPÉRATEURS DE COMPARAISON :
 *    - Comparaison directe des rawBits (entiers)
 *    - Complexité O(1) pour toutes les comparaisons
 *    - Retour de bool pour compatibilité avec les algorithmes STL
 * 
 * 2. OPÉRATEURS ARITHMÉTIQUES :
 *    - Addition/Soustraction : rawBits ± rawBits (pas de correction)
 *    - Multiplication : (rawBits * rawBits) >> 8 (division par 2^8)
 *    - Division : ((rawBits << 8) / rawBits) (multiplication par 2^8)
 *    - Gestion de la division par zéro
 * 
 * 3. OPÉRATEURS D'INCRÉMENTATION :
 *    - Pré-incrémentation (++a) : incrémente puis retourne
 *    - Post-incrémentation (a++) : retourne puis incrémente
 *    - Différence cruciale : pré retourne référence, post retourne copie
 *    - Incrémentation de 1/256 (epsilon tel que 1 + ε > 1)
 * ============================================================================
 */

