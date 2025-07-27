
Dossier de rendu : ex00/
Fichiers à rendre : Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp
Fonctions interdites : Aucune

Si vous pensiez connaître les entiers et les flottants, cet article de 3 pages (1, 2, 3)
vous montrera que ce n’est sans doute pas le cas. Allez, lisez-le.
Jusqu’à aujourd’hui, tous les nombres utilisés dans votre code étaient soit des entiers,
soit des flottants, soit éventuellement leurs dérivés (short, char, long, double, etc.).
Après avoir lu l’article ci-dessus, il paraît évident d’affirmer que les caractéristiques des
entiers et des nombres à virgule flottante sont opposées.
Mais aujourd’hui, les choses vont changer. Vous allez découvrir une notion inédite et
passionnante : la représentation des nombres en virgule fixe ! À jamais absents des
types scalaires de la plupart des langages, les nombres à virgule fixe offrent un équilibre
intéressant entre performance, exactitude, portée et précision. Cela explique pourquoi
ces nombres sont largement utilisés dans l’imagerie numérique, le domaine du son ou la
programmation scientifique, pour n’en citer que trois.
Étant donné que le C++ ne possède pas de nombres à virgule fixe, vous allez les
ajouter. Cet article de Berkeley est un bon point de départ. Si vous ne savez pas ce qu’est
l’Université de Berkeley, lisez cette partie de sa page Wikipédia.


Créez une classe sous forme canonique pour représenter un nombre à virgule fixe.
• Membres privés :
◦ Un entier pour stocker la valeur du nombre en virgule fixe.
◦ Un entier constant statique pour stocker le nombre de bits de la partie
fractionnaire, et dont la valeur sera toujours le littéral entier 8.
• Membres publics :
◦ Un constructeur par défaut qui initialisera la valeur du nombre à virgule fixe
à 0.
◦ Un constructeur de recopie.
◦ Une surcharge de l’opérateur d’affectation.
◦ Un destructeur.
◦ Une fonction membre int getRawBits( void ) const;
qui retourne la valeur du nombre à virgule fixe sans la convertir.
◦ Une fonction membre void setRawBits( int const raw );
qui initialise la valeur du nombre à virgule fixe avec celle passée en paramètre.

Exécuter ce code :

#include <iostream>
int main( void ) {
Fixed a;
Fixed b( a );
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
return 0;
}

Devrait afficher ce résultat :
$> ./a.out
Default constructor called
Copy constructor called
Copy assignment operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destr