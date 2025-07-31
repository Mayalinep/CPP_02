L’exercice précédent était un bon point de départ mais notre classe n’a pour l’instant
pas beaucoup d’intérêt. Elle peut seulement représenter la valeur 0.0.
Ajoutez à votre classe les constructeurs et les fonctions membres suivants en public :
• Un constructeur prenant un entier constant en paramètre et qui convertit celuici en virgule fixe. Le nombre de bits de la partie fractionnaire est initialisé à 8
comme dans l’exercice 00.
• Un constructeur prenant un flottant constant en paramètre et qui convertit
celui-ci en virgule fixe. Le nombre de bits de la partie fractionnaire est initialisé à
8 comme dans l’exercice 00.
• Une fonction membre float toFloat( void ) const;
qui convertit la valeur en virgule fixe en nombre à virgule flottante.
• Une fonction membre int toInt( void ) const;
qui convertit la valeur en virgule fixe en nombre entier.
Ajoutez également la fonction suivante à vos fichiers de la classe Fixed :
• Une surcharge de l’opérateur d’insertion («) qui insère une représentation en virgule flottante du nombre à virgule fixe dans le flux de sortie (objet output stream)
passé en paramètre.

Exécuter ce code :
#include <iostream>
int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}

$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
$>