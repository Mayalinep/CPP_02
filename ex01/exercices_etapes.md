# Exercices étape par étape - Ex01

## Étape 1 : Corriger les erreurs de syntaxe

### Problème 1 : Erreur de frappe
Dans `Fixed.cpp` ligne 25, tu as écrit `Fixd::Fixed` au lieu de `Fixed::Fixed`

### Problème 2 : Fonctions incomplètes
Les fonctions `toFloat()` et `toInt()` sont vides.

## Étape 2 : Compléter les constructeurs

### Constructeur avec int
**Question** : Comment convertir l'entier 10 en virgule fixe avec 8 bits fractionnaires ?

**Indice** : 
- Si tu veux représenter 10.0 en virgule fixe
- Avec 8 bits fractionnaires, tu dois multiplier par 2^8 = 256
- Donc 10 * 256 = 2560

**À faire** : Complète le constructeur `Fixed(const int raw)`

### Constructeur avec float
**Question** : Comment convertir 42.42f en virgule fixe ?

**Indice** :
- Même principe : multiplier par 256
- 42.42 * 256 = 10859.52
- Arrondir à l'entier le plus proche : 10860

**À faire** : Complète le constructeur `Fixed(const float raw)`

## Étape 3 : Compléter les fonctions de conversion

### toFloat()
**Question** : Comment reconvertir `rawBits` en float ?

**Indice** :
- Division par 256 (2^8)
- `return (float)rawBits / 256.0f;`

### toInt()
**Question** : Comment obtenir la partie entière ?

**Indice** :
- Division entière par 256
- `return rawBits / 256;`

## Étape 4 : Surcharge de l'opérateur <<

**Question** : Où déclarer cette fonction ?

**Indice** :
- En dehors de la classe
- Dans le header, après la classe
- `std::ostream& operator<<(std::ostream& os, const Fixed& fixed);`

**Question** : Comment l'implémenter ?

**Indice** :
- Utiliser `toFloat()` pour la conversion
- `os << fixed.toFloat();`

## Exercices pratiques :

### Exercice 1 : Test simple
Crée un petit programme pour tester :
```cpp
Fixed a(10);
Fixed b(42.42f);
std::cout << "a = " << a.toFloat() << std::endl;
std::cout << "b = " << b.toFloat() << std::endl;
```

### Exercice 2 : Vérification
- 10 devrait donner 10.0
- 42.42f devrait donner environ 42.42

Essaie de corriger et compléter étape par étape ! 