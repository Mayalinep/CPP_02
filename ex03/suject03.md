BSP
Dossier de rendu : ex03/
Fichiers à rendre : Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp,
Point.{h, hpp}, Point.cpp, bsp.cpp
Fonctions Autorisées : roundf (from <cmath>)

Maintenant que vous avez une classe Fixed fonctionnelle, ce serait sympa de l’utiliser
non ?
Implémentez une fonction qui indique si un point donné est à l’intérieur d’un triangle.
Super utile, n’est-ce pas ?

Premièrement, créez une classe Point sous forme canonique pour représenter un point
2D :
• Membres privés :
◦ Un attribut Fixed constant x.
◦ Un attribut Fixed constant y.
◦ Et tout ce qui peut vous être utile.
• Membres publics :
◦ Un constructeur par défaut qui initialise x et y à 0.
◦ Un constructeur prenant deux flottants constants en paramètres et initialisant
x et y avec ces derniers.
◦ Un constructeur de recopie.
◦ Une surcharge de l’opérateur d’affectation.
◦ Un destructeur.
◦ Et tout ce qui peut vous être utile.
Pour conclure, implémentez la fonction suivante dans le fichier correspondant :
bool bsp( Point const a, Point const b, Point const c, Point const point);
• a, b, c : Les sommets de notre cher triangle.
• point : Le point à évaluer.
• Retourne : True si le point est à l’intérieur du triangle. False dans le cas contraire.
Cela veut dire que, si le point est un sommet ou placé sur une arrête, la fonction
retournera False.
Écrivez et rendez vos propres tests afin de démontrer que votre classe fonctionne
comme demandé.