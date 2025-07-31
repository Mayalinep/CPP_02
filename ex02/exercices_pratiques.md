# Exercices Pratiques - Surcharge d'opérateurs

## Exercice 1 : Comprendre les opérateurs de comparaison

### Question 1.1
Imagine que tu as deux objets `Fixed` : `a` avec la valeur 5.5 et `b` avec la valeur 3.2.
- Que devrait retourner `a > b` ?
- Que devrait retourner `a == b` ?
- Que devrait retourner `a != b` ?

### Question 1.2
Réfléchis à l'implémentation :
- Comment compares-tu deux nombres à virgule fixe ?
- Faut-il les convertir en float d'abord ?
- Ou peux-tu les comparer directement avec leurs valeurs entières ?

## Exercice 2 : Comprendre les opérateurs arithmétiques

### Question 2.1
Si tu as `Fixed a(5.5)` et `Fixed b(2.0)` :
- Que devrait être le résultat de `a + b` ?
- Que devrait être le résultat de `a * b` ?
- Est-ce que `a` et `b` doivent être modifiés après l'opération ?

### Question 2.2
Réfléchis à l'implémentation :
- Comment effectues-tu une addition entre deux Fixed ?
- Le résultat doit-il être un nouvel objet ou modifier l'existant ?
- Pourquoi ?

## Exercice 3 : Comprendre l'incrémentation

### Question 3.1
Avec `Fixed a(5.0)` :
- Que devrait être le résultat de `++a` ?
- Que devrait être le résultat de `a++` ?
- Quelle est la différence entre les deux ?

### Question 3.2
Réfléchis à l'epsilon :
- Quelle est la plus petite valeur représentable dans ton système ?
- Comment calcules-tu cette valeur avec tes bits fractionnaires ?
- Pourquoi cette valeur est-elle importante pour l'incrémentation ?

## Exercice 4 : Comprendre les fonctions statiques

### Question 4.1
Pourquoi avoir deux versions de `max` :
- Une qui prend des références non-constantes
- Une qui prend des références constantes

### Question 4.2
Quand utiliser quelle version :
- Si tu veux juste comparer deux valeurs ?
- Si tu veux pouvoir modifier les paramètres dans la fonction ?

## Exercice 5 : Réflexion sur la syntaxe

### Question 5.1
Pour un opérateur de comparaison `>` :
- Quelle est la signature de la fonction ?
- Doit-elle être membre de la classe ?
- Doit-elle être const ?

### Question 5.2
Pour un opérateur arithmétique `+` :
- Quelle est la signature de la fonction ?
- Que doit-elle retourner ?
- Doit-elle modifier l'objet courant ?

## Exercice 6 : Analyse du code de test

Regarde le code de test fourni dans le sujet :

```cpp
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << ++a << std::endl;
std::cout << a++ << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
```

### Question 6.1
- Que fait `Fixed( 5.05f ) * Fixed( 2 )` ?
- Pourquoi le résultat est-il `10.1016` et pas `10.1` exactement ?

### Question 6.2
- Pourquoi `++a` et `a++` donnent-ils des résultats différents ?
- Comment expliques-tu les valeurs affichées ?

## Tes réponses

Écris tes réponses ici :

### Exercice 1
1.1. 
- a > b devrait retourner : vrai
- a == b devrait retourner : faux
- a != b devrait retourner : vrai

1.2. 
- Ma stratégie de comparaison : comparer le rawbits de rhs et celui de l element en cours

### Exercice 2
2.1.
- a + b devrait être : 5.5 + 3.2
- a * b devrait être : 5.5 * 3.2
- Modification des objets : c est de const donc non 

2.2.
- Ma stratégie d'implémentation :  

### Exercice 3
3.1.
- ++a devrait être : 
- a++ devrait être : 
- Différence : 

3.2.
- Epsilon dans mon système : 
- Calcul : 

### Exercice 4
4.1.
- Version non-constante : 
- Version constante : 

4.2.
- Quand utiliser non-const : 
- Quand utiliser const : 

### Exercice 5
5.1.
- Signature pour > : 
- Membre de classe : 
- Const : 

5.2.
- Signature pour + : 
- Retour : 
- Modification : 

### Exercice 6
6.1.
- Fixed( 5.05f ) * Fixed( 2 ) fait : 
- Résultat 10.1016 car : 

6.2.
- Différence ++a vs a++ : 
- Valeurs affichées car : 