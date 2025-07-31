# Analyse de l'exercice 01 - Constructeurs et conversions

## Ce qui est demandé

### 1. Constructeurs à ajouter :
- **Constructeur avec int** : prend un entier et le convertit en virgule fixe
- **Constructeur avec float** : prend un flottant et le convertit en virgule fixe

### 2. Fonctions membres à ajouter :
- `float toFloat(void) const` : convertit la valeur virgule fixe en float
- `int toInt(void) const` : convertit la valeur virgule fixe en int

### 3. Surcharge d'opérateur :
- Surcharge de l'opérateur `<<` pour afficher la valeur en virgule flottante

## Questions pour t'aider à réfléchir :

### 1. Conversion int → virgule fixe :
- Comment représenter un entier en virgule fixe avec 8 bits fractionnaires ?
- Si tu as l'entier 10, comment le stocker dans `_value` ?

### 2. Conversion float → virgule fixe :
- Comment convertir 42.42f en virgule fixe ?
- Quelle formule utiliser ?

### 3. Conversion virgule fixe → float :
- Comment reconvertir `_value` en float ?
- Quelle formule inverse utiliser ?

### 4. Conversion virgule fixe → int :
- Comment obtenir la partie entière de ta valeur virgule fixe ?

### 5. Surcharge de l'opérateur << :
- Comment déclarer cette fonction ?
- Où la placer (dans la classe ou en dehors) ?

## Indices :
- Pense aux décalages de bits (<< et >>)
- Pour la conversion float → virgule fixe : multiplication par 2^8
- Pour la conversion virgule fixe → float : division par 2^8
- Pour la partie entière : division entière par 2^8

Essaie de répondre à ces questions avant de commencer le code ! 