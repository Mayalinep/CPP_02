Ajoutez à votre classe des fonctions membres publiques afin de surcharger les opérateurs suivants :
• Les 6 opérateur de comparaison : >, <, >=, <=, == et !=.
• Les 4 opérateurs de arithmétiques : +, -, *, et /.
• Les 4 opérateurs d’incrémentation et de décrémentation (pré-incrémentation et
post-incrémentation, pré-décrémentation et post-décrémentation) qui diminueront
la valeur du nombre à virgule fixe d’unité ϵ tel que 1 + ϵ > 1.

Ajoutez à votre classe ces quatre fonctions membres publiques surchargées :
• Une fonction membre statique min prenant en paramètres deux références sur des
nombres à virgule fixe et qui retourne le plus petit d’entre eux.
• Une fonction membre statique min prenant en paramètres deux références sur des
nombres à virgule fixe constants et qui retourne le plus petit d’entre eux.
• Une fonction membre statique max prenant en paramètres deux références sur des
nombres à virgule fixe et qui retourne le plus grand d’entre eux.
• Une fonction membre statique max prenant en paramètres deux références sur des
nombres à virgule fixe constants et qui retourne le plus grand d’entre eux.

C’est à vous de tester chaque fonctionnalité de votre code. Mais exécuter ce code :

```
#include <iostream>

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

	return 0;
}
```
Devra afficher ce résultat (pour plus de lisibilité, les messages du constructeur et du
destructeur ont été retirés) :

```
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
```