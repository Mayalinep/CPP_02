/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:18:17 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/31 13:19:29 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	
	// Création d'un objet Fixed avec constructeur par défaut (valeur 0)
	Fixed a;
	
	// Utilisation du constructeur de copie pour créer 'b' à partir de 'a'
	Fixed b( a );

	// Création d'un objet 'c' avec constructeur par défaut
	Fixed c;

	// Utilisation de l'opérateur d'affectation pour copier 'b' dans 'c'
	c = b;

	// Affichage des valeurs brutes (_rawBits) de chaque objet
	// Résultat attendu : 0 pour tous (représentation de 0.0 en virgule fixe)
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
return 0;
}

/*
 * ============================================================================
 * DÉMONSTRATION DES CONCEPTS DE VIRGULE FIXE (FIXED-POINT ARITHMETIC)
 * ============================================================================
 * 
 * Ce programme illustre l'implémentation d'une classe Fixed qui utilise
 * l'arithmétique en virgule fixe pour représenter des nombres décimaux
 * avec une précision constante de 8 bits fractionnaires.
 * 
 * CONCEPTS CLÉS DÉMONTRÉS :
 * 
 * 1. REPRÉSENTATION EN VIRGULE FIXE :
 *    - Les nombres sont stockés sous forme d'entiers 32 bits
 *    - Les 8 bits de poids faible représentent la partie fractionnaire
 *    - Les 24 bits de poids fort représentent la partie entière
 *    - Format : [23 bits entiers].[8 bits fractionnaires]
 * 
 * 2. PRÉCISION ET RANGE :
 *    - Précision : 1/256 (2^-8) pour la partie fractionnaire
 *    - Range entier : -8,388,608 à +8,388,607
 *    - Plus grande précision que les entiers, moins que les float
 * 
 * 3. AVANTAGES DE LA VIRGULE FIXE :
 *    - Prédictibilité des performances (pas d'arrondi variable)
 *    - Représentation exacte pour certains nombres décimaux
 *    - Idéal pour les systèmes embarqués et temps réel
 * 
 * 4. CONSTRUCTEURS ET SÉMANTIQUE DE COPIE :
 *    - Constructeur par défaut : initialise à 0.0
 *    - Constructeur de copie : copie bit à bit (deep copy)
 *    - Opérateur d'affectation : gestion de l'auto-assignation
 * 
 * ANALYSE DES PERFORMANCES ET COMPLEXITÉ :
 * - TEMPS : O(1) pour toutes les opérations
 * - ESPACE : O(1) - chaque objet occupe 4 bytes (32 bits)
 * 
 * COMPARAISON AVEC LES TYPES NATIFS :
 * - float/double : Précision variable, arrondis imprévisibles
 * - int : Pas de partie fractionnaire
 * - Fixed : Précision constante, performances prédictibles
 * 
 * ============================================================================
 */