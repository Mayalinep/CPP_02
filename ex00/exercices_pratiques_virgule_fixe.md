# 🎯 Exercices Pratiques - Nombres à Virgule Fixe

## 📝 Niveau 1 : Conversions de base

### Exercice 1.1 - Int vers Fixed
Convertis les entiers suivants en format Fixed (8 bits fractionnaires) :

a) `7` → ?
b) `15` → ?
c) `100` → ?
d) `255` → ?

**Indice :** Multiplie par 256 !

### Exercice 1.2 - Vérification binaire
Pour chaque résultat de l'exercice 1.1, écris la représentation binaire complète (32 bits).

### Exercice 1.3 - Fixed vers Int
Convertis les valeurs Fixed suivantes en entiers :

a) `rawBits = 1792` → ?
b) `rawBits = 3840` → ?
c) `rawBits = 25600` → ?
d) `rawBits = 65280` → ?

## 🔍 Niveau 2 : Float vers Fixed

### Exercice 2.1 - Conversions simples
Convertis les floats suivants en format Fixed :

a) `0.5` → ?
b) `0.25` → ?
c) `0.125` → ?
d) `0.0625` → ?

### Exercice 2.2 - Avec roundf()
Calcule la différence entre ces deux approches :

```cpp
// Approche 1 (sans roundf)
float f = 2.7f;
int result1 = (int)(f * 256);

// Approche 2 (avec roundf)
float f = 2.7f;
int result2 = (int)roundf(f * 256);
```

### Exercice 2.3 - Conversions complexes
Convertis ces floats en Fixed :

a) `3.75` → ?
b) `7.125` → ?
c) `10.5` → ?
d) `15.875` → ?

## 🧮 Niveau 3 : Représentation binaire

### Exercice 3.1 - Décomposition binaire
Décompose ces nombres en binaire étape par étape :

a) `1280` (5.0)
b) `704` (2.75)
c) `1920` (7.5)

### Exercice 3.2 - Visualisation
Dessine la représentation binaire de `6.25` :

```
┌─────────────────────────────────────────────────────────────┐
│                   32 bits                                  │
├─────────────────┬─────────────────────────────────────────┤
│                 │                                        │
│  ←─── Partie entière ───→│←─ Partie fractionnaire ─→│
└─────────────────┴─────────────────────────────────────────┘
```

### Exercice 3.3 - Interprétation
Quelle valeur décimale représente ce pattern binaire ?
```
00000000 00000000 00000101 10000000
```

## 🔧 Niveau 4 : Implémentation

### Exercice 4.1 - Fonction toDouble()
Écris une fonction qui convertit un Fixed vers un double :

```cpp
double toDouble(void) const;
```

### Exercice 4.2 - Fonction isInteger()
Écris une fonction qui vérifie si un Fixed représente un nombre entier :

```cpp
bool isInteger(void) const;
```

### Exercice 4.3 - Fonction getFractionalPart()
Écris une fonction qui retourne la partie fractionnaire d'un Fixed :

```cpp
int getFractionalPart(void) const;
```

## 🎯 Niveau 5 : Cas limites et problèmes

### Exercice 5.1 - Précision
Quelle est la plus petite différence entre deux nombres Fixed consécutifs ?

### Exercice 5.2 - Débordement
Que se passe-t-il si on essaie de représenter `1000000.0` avec 8 bits fractionnaires ?

### Exercice 5.3 - Erreurs de calcul
Analyse ce code et trouve l'erreur :

```cpp
Fixed::Fixed(const float raw) {
    const int scale = 1 << value_bits;
    rawBits = raw * scale;  // ❌ Problème ici
}
```

## 🔍 Niveau 6 : Debugging

### Exercice 6.1 - Analyse d'erreur
Pourquoi cette ligne peut causer des problèmes ?

```cpp
int Fixed::toInt(void) const {
    return rawBits / (1 << value_bits);  // ❌ Problème potentiel
}
```

### Exercice 6.2 - Comparaison de précision
Compare la précision de ces deux approches :

```cpp
// Approche 1
float f1 = 3.14159f;
Fixed fixed1(f1);

// Approche 2
double d = 3.14159;
Fixed fixed2((float)d);
```

## 📊 Niveau 7 : Problèmes complexes

### Exercice 7.1 - Série de conversions
Effectue cette série de conversions :

```
42 → Fixed → Float → Fixed → Int
```

### Exercice 7.2 - Calculs avec Fixed
Implémente ces opérations pour la classe Fixed :

```cpp
Fixed operator+(const Fixed& rhs) const;
Fixed operator-(const Fixed& rhs) const;
Fixed operator*(const Fixed& rhs) const;
Fixed operator/(const Fixed& rhs) const;
```

### Exercice 7.3 - Comparaisons
Implémente ces opérateurs de comparaison :

```cpp
bool operator==(const Fixed& rhs) const;
bool operator!=(const Fixed& rhs) const;
bool operator<(const Fixed& rhs) const;
bool operator>(const Fixed& rhs) const;
```

## 🎓 Niveau 8 : Réflexion et optimisation

### Exercice 8.1 - Optimisation mémoire
Quels seraient les avantages et inconvénients d'utiliser :
- 16 bits fractionnaires au lieu de 8 ?
- 4 bits fractionnaires au lieu de 8 ?

### Exercice 8.2 - Applications réelles
Dans quels cas utiliserais-tu les nombres à virgule fixe plutôt que les float ?

### Exercice 8.3 - Extension du concept
Comment implémenterais-tu des nombres à virgule fixe avec :
- Une précision variable ?
- Des opérations de troncature ?
- Des conversions vers d'autres bases ?

---

## 📋 Réponses (à vérifier après avoir essayé)

<details>
<summary>Cliquez pour voir les réponses</summary>

### Exercice 1.1
a) 7 → 1792 (7 * 256)
b) 15 → 3840 (15 * 256)
c) 100 → 25600 (100 * 256)
d) 255 → 65280 (255 * 256)

### Exercice 1.2
a) 1792 = 00000000 00000000 00000111 00000000
b) 3840 = 00000000 00000000 00001111 00000000
c) 25600 = 00000000 00000000 01100100 00000000
d) 65280 = 00000000 00000000 11111111 00000000

### Exercice 1.3
a) 1792 → 7 (1792/256)
b) 3840 → 15 (3840/256)
c) 25600 → 100 (25600/256)
d) 65280 → 255 (65280/256)

### Exercice 2.1
a) 0.5 → 128 (0.5 * 256)
b) 0.25 → 64 (0.25 * 256)
c) 0.125 → 32 (0.125 * 256)
d) 0.0625 → 16 (0.0625 * 256)

### Exercice 2.2
result1 = 691 (perte de précision)
result2 = 691 (même résultat car 2.7 * 256 = 691.2, arrondi à 691)

### Exercice 2.3
a) 3.75 → 960 (3.75 * 256)
b) 7.125 → 1824 (7.125 * 256)
c) 10.5 → 2688 (10.5 * 256)
d) 15.875 → 4064 (15.875 * 256)

### Exercice 3.3
00000000 00000000 00000101 10000000 = 1408
1408/256 = 5.5

### Exercice 5.1
Plus petite différence : 1/256 ≈ 0.0039

### Exercice 5.2
1000000 * 256 = 256000000 > 2³¹ (débordement !)

### Exercice 6.1
La division peut donner des résultats incorrects pour les nombres négatifs.

</details>

## 🎯 Conseils pour réussir

1. **Prends ton temps** pour chaque exercice
2. **Vérifie tes calculs** étape par étape
3. **Utilise une calculatrice** pour les conversions
4. **Dessine les schémas** pour visualiser
5. **Teste tes implémentations** avec différents cas

**Bonne chance ! Tu vas devenir une experte des nombres à virgule fixe !** 🚀 