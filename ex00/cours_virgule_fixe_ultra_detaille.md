# 📚 Cours Ultra-Détaillé : Les Nombres à Virgule Fixe

## 🎯 Introduction - Pourquoi ce cours ?

Tu veux tout comprendre sur les nombres à virgule fixe ? Parfait ! Je vais te prendre par la main et t'expliquer **chaque détail**, même ceux qui semblent évidents. On va partir de zéro et aller jusqu'au bout !

## 🔍 Chapitre 1 : Les Bases du Système Binaire

### 1.1 Qu'est-ce que le système binaire ?

Le système binaire utilise seulement 2 chiffres : **0** et **1**

**Exemple :** Le nombre 42 en décimal
```
42 = 4 × 10¹ + 2 × 10⁰ = 40 + 2 = 42
```

### 1.2 Conversion décimal → binaire

**Méthode par divisions successives :**

```
42 ÷ 2 = 21 reste 0
21 ÷ 2 = 10 reste 1
10 ÷ 2 = 5  reste 0
5  ÷ 2 = 2  reste 1
2  ÷ 2 = 1  reste 0
1  ÷ 2 = 0  reste 1
```

**Lecture de bas en haut :** 101010

**Vérification :**
```
101010 = 1×2⁵ + 0×2⁴ + 1×2³ + 0×2² + 1×2¹ + 0×2⁰
       = 32 + 0 + 8 + 0 + 2 + 0
       = 42 ✅
```

### 1.3 Les puissances de 2

```
2⁰ = 1
2¹ = 2
2² = 4
2³ = 8
2⁴ = 16
2⁵ = 32
2⁶ = 64
2⁷ = 128
2⁸ = 256  ← IMPORTANT pour notre Fixed !
2⁹ = 512
2¹⁰ = 1024
```

## 🏗️ Chapitre 2 : Structure d'un Nombre à Virgule Fixe

### 2.1 Qu'est-ce qu'un nombre à virgule fixe ?

C'est une façon de représenter des nombres décimaux avec des entiers, où la position de la virgule est **fixe**.

### 2.2 Notre structure Fixed (32 bits)

```
┌──────────────────────────────────────────────────────────────┐
│                   32 bits (int)                              │
├─────────────────────────────┬────────────────────────────────┤ 
│   Partie entière (24 bits)  │  Partie fractionnaire (8 bits) │
└─────────────────────────────┴────────────────────────────────┘
```

**Explication :**
- **24 bits** pour la partie entière
- **8 bits** pour la partie fractionnaire
- **Position de la virgule** : entre le bit 23 et le bit 24

### 2.3 Visualisation détaillée

```
┌─────────┬─────────┬─────────┬─────────┐
│   Bit 31│   Bit 23│   Bit 15│   Bit 7 │
│   (MSB) │         │         │   (LSB) │
├─────────┼─────────┼─────────┼─────────┤
│ 11111111│11111111│11111111│11111111│
│  ← Partie entière → │← Fraction →│
└─────────┴─────────┴─────────┴─────────┘
```

## 🧮 Chapitre 3 : Conversion d'un Entier vers Fixed

### 3.1 Le processus étape par étape 

**Étape 1 :** Prendre l'entier
**Étape 2 :** Multiplier par 256 (2⁸)
**Étape 3 :** Stocker le résultat dans rawBits

### 3.2 Exemple détaillé avec 42

#### Étape 1 : 42 en binaire
```
42 = 101010 en binaire
   = 00000000 00000000 00000000 00101010 (32 bits)
```

#### Étape 2 : Multiplication par 256
```
42 × 256 = 10752
```

**Décomposition de 10752 :**
```
10752 ÷ 2 = 5376 reste 0
5376  ÷ 2 = 2688 reste 0
2688  ÷ 2 = 1344 reste 0
1344  ÷ 2 = 672  reste 0
672   ÷ 2 = 336  reste 0
336   ÷ 2 = 168  reste 0
168   ÷ 2 = 84   reste 0
84    ÷ 2 = 42   reste 0
42    ÷ 2 = 21   reste 0
21    ÷ 2 = 10   reste 1
10    ÷ 2 = 5    reste 0
5     ÷ 2 = 2    reste 1
2     ÷ 2 = 1    reste 0
1     ÷ 2 = 0    reste 1
```

**Lecture de bas en haut :** 10101000000000

**En 32 bits :** 00000000 00000000 00101010 00000000

#### Étape 3 : Vérification
```
00000000 00000000 00101010 00000000
= 0×2³¹ + 0×2³⁰ + ... + 1×2¹⁵ + 0×2¹⁴ + 1×2¹³ + 0×2¹² + 1×2¹¹ + 0×2¹⁰ + 0×2⁹ + 0×2⁸ + 0×2⁷ + 0×2⁶ + 0×2⁵ + 0×2⁴ + 0×2³ + 0×2² + 0×2¹ + 0×2⁰
= 32768 + 8192 + 2048 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0
= 43008 ❌
```

**Attendez !** Il y a une erreur dans mon calcul. Laissez-moi corriger :

```
00000000 00000000 00101010 00000000
= 0×2³¹ + 0×2³⁰ + ... + 0×2²⁴ + 0×2²³ + 1×2²² + 0×2²¹ + 1×2²⁰ + 0×2¹⁹ + 1×2¹⁸ + 0×2¹⁷ + 0×2¹⁶ + 0×2¹⁵ + 0×2¹⁴ + 0×2¹³ + 0×2¹² + 0×2¹¹ + 0×2¹⁰ + 0×2⁹ + 0×2⁸ + 0×2⁷ + 0×2⁶ + 0×2⁵ + 0×2⁴ + 0×2³ + 0×2² + 0×2¹ + 0×2⁰
= 4194304 + 0 + 1048576 + 0 + 262144 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0
= 5505024 ❌
```

**Encore une erreur !** Laissez-moi refaire le calcul correctement :

```
00000000 00000000 00101010 00000000
= 0×2³¹ + 0×2³⁰ + ... + 0×2²⁴ + 0×2²³ + 1×2²² + 0×2²¹ + 1×2²⁰ + 0×2¹⁹ + 1×2¹⁸ + 0×2¹⁷ + 0×2¹⁶ + 0×2¹⁵ + 0×2¹⁴ + 0×2¹³ + 0×2¹² + 0×2¹¹ + 0×2¹⁰ + 0×2⁹ + 0×2⁸ + 0×2⁷ + 0×2⁶ + 0×2⁵ + 0×2⁴ + 0×2³ + 0×2² + 0×2¹ + 0×2⁰
= 0 + 0 + ... + 0 + 0 + 4194304 + 0 + 1048576 + 0 + 262144 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0
= 5505024
```

**Attendez !** Je me trompe encore. Le problème est que je compte les bits de droite à gauche. Laissez-moi corriger :

```
00000000 00000000 00101010 00000000
= 0×2³¹ + 0×2³⁰ + ... + 0×2¹⁶ + 0×2¹⁵ + 1×2¹⁴ + 0×2¹³ + 1×2¹² + 0×2¹¹ + 1×2¹⁰ + 0×2⁹ + 0×2⁸ + 0×2⁷ + 0×2⁶ + 0×2⁵ + 0×2⁴ + 0×2³ + 0×2² + 0×2¹ + 0×2⁰
= 0 + 0 + ... + 0 + 0 + 16384 + 0 + 4096 + 0 + 1024 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0
= 21504 ❌
```

**Je me trompe complètement !** Laissez-moi reprendre depuis le début avec une approche plus simple :

### 3.3 Méthode simple pour vérifier

**42 × 256 = 10752**

Vérifions que 10752 correspond bien à notre représentation :

```
10752 ÷ 2 = 5376 reste 0
5376  ÷ 2 = 2688 reste 0
2688  ÷ 2 = 1344 reste 0
1344  ÷ 2 = 672  reste 0
672   ÷ 2 = 336  reste 0
336   ÷ 2 = 168  reste 0
168   ÷ 2 = 84   reste 0
84    ÷ 2 = 42   reste 0
42    ÷ 2 = 21   reste 0
21    ÷ 2 = 10   reste 1
10    ÷ 2 = 5    reste 0
5     ÷ 2 = 2    reste 1
2     ÷ 2 = 1    reste 0
1     ÷ 2 = 0    reste 1
```

**Lecture de bas en haut :** 10101000000000

**En 32 bits :** 00000000 00000000 00101010 00000000

**Vérification :**
```
10101000000000 = 1×2¹³ + 0×2¹² + 1×2¹¹ + 0×2¹⁰ + 1×2⁹ + 0×2⁸ + 0×2⁷ + 0×2⁶ + 0×2⁵ + 0×2⁴ + 0×2³ + 0×2² + 0×2¹ + 0×2⁰
= 8192 + 0 + 2048 + 0 + 512 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0
= 10752 ✅
```

### 3.4 Visualisation du décalage

```
Avant multiplication par 256 :
┌─────────────────────────────────────────────────────────────┐
│                   32 bits                                   │
├─────────────────┬────────────────────────────────────────  ─┤
│  00000000 00000000 00000000│00101010                    │
│  ←─── Partie entière (0) ───→│←─ Partie fractionnaire ─→│
└─────────────────┴─────────────────────────────────────────┘

Après multiplication par 256 (décalage de 8 bits) :
┌─────────────────────────────────────────────────────────────┐
│                   32 bits                                  │
├─────────────────┬─────────────────────────────────────────┤
│  00000000 00000000│00101010 00000000                    │
│  ←─ Partie entière (42) ─→│←─ Fraction (0) ─→│
└─────────────────┴─────────────────────────────────────────┘
```

## 🔄 Chapitre 4 : Conversion d'un Float vers Fixed

### 4.1 Le processus étape par étape

**Étape 1 :** Prendre le float
**Étape 2 :** Multiplier par 256
**Étape 3 :** Utiliser rounAdf() pour arrondir
**Étape 4 :** Convertir en int

### 4.2 Exemple détaillé avec 3.14

#### Étape 1 : 3.14 en binaire (approximation)

**3.14 en décimal = 3 + 0.14**

**Partie entière (3) :**
```
3 = 11 en binaire
```

**Partie fractionnaire (0.14) :**
```
0.14 × 2 = 0.28 → 0
0.28 × 2 = 0.56 → 0
0.56 × 2 = 1.12 → 1
0.12 × 2 = 0.24 → 0
0.24 × 2 = 0.48 → 0
0.48 × 2 = 0.96 → 0
0.96 × 2 = 1.92 → 1
0.92 × 2 = 1.84 → 1
...
```

**Donc 0.14 ≈ 0.00100011... en binaire**

**3.14 ≈ 1100100011.000000000... en binaire**

#### Étape 2 : Multiplication par 256
```
3.14 × 256 = 803.84
```

#### Étape 3 : Utilisation de roundf()
```
roundf(803.84) = 804.0
```

#### Étape 4 : Conversion en int
```
(int)804.0 = 804
```

### 4.3 Décomposition binaire de 804

```
804 ÷ 2 = 402 reste 0
402 ÷ 2 = 201 reste 0
201 ÷ 2 = 100 reste 1
100 ÷ 2 = 50  reste 0
50  ÷ 2 = 25  reste 0
25  ÷ 2 = 12  reste 1
12  ÷ 2 = 6   reste 0
6   ÷ 2 = 3   reste 0
3   ÷ 2 = 1   reste 1
1   ÷ 2 = 0   reste 1
```

**Lecture de bas en haut :** 1100100100

**En 32 bits :** 00000000 00000000 00000011 00100100

### 4.4 Vérification de 804
```
1100100100 = 1×2⁹ + 1×2⁸ + 0×2⁷ + 0×2⁶ + 1×2⁵ + 0×2⁴ + 0×2³ + 1×2² + 0×2¹ + 0×2⁰
= 512 + 256 + 0 + 0 + 32 + 0 + 0 + 4 + 0 + 0
= 804 ✅
```

### 4.5 Pourquoi roundf() est important ?

**Sans roundf() :**
```
3.14 × 256 = 803.84
(int)803.84 = 803
```

**Avec roundf() :**
```
3.14 × 256 = 803.84
roundf(803.84) = 804.0
(int)804.0 = 804
```

**Différence :**
```
803/256 = 3.13671875
804/256 = 3.140625
```

**La vraie valeur :** 3.14

**Erreur sans roundf() :** 3.14 - 3.13671875 = 0.00328125
**Erreur avec roundf() :** 3.140625 - 3.14 = 0.000625

**roundf() donne une meilleure précision !**

## 🔧 Chapitre 5 : Conversion de Fixed vers Float

### 5.1 Le processus étape par étape

**Étape 1 :** Prendre rawBits
**Étape 2 :** Diviser par 256
**Étape 3 :** Convertir en float

### 5.2 Exemple détaillé avec rawBits = 804

#### Étape 1 : 804 en binaire
```
804 = 00000000 00000000 00000011 00100100
```

#### Étape 2 : Division par 256
```
804 ÷ 256 = 3.140625
```

#### Étape 3 : Conversion en float
```
(float)3.140625 = 3.140625f
```

### 5.3 Vérification
```
3.140625 ≈ 3.14 ✅
```

## 🔄 Chapitre 6 : Conversion de Fixed vers Int

### 6.1 Le processus étape par étape

**Étape 1 :** Prendre rawBits
**Étape 2 :** Décaler de 8 bits vers la droite (division par 256)
**Étape 3 :** Résultat = partie entière

### 6.2 Exemple détaillé avec rawBits = 10752

#### Étape 1 : 10752 en binaire
```
10752 = 00000000 00000000 00101010 00000000
```

#### Étape 2 : Décalage de 8 bits vers la droite
```
00000000 00000000 00101010 00000000 >> 8
= 00000000 00000000 00000000 00101010
= 42
```

#### Étape 3 : Vérification
```
42 ✅
```

### 6.3 Exemple avec rawBits = 804 (3.14)

#### Étape 1 : 804 en binaire
```
804 = 00000000 00000000 00000011 00100100
```

#### Étape 2 : Décalage de 8 bits vers la droite
```
00000000 00000000 00000011 00100100 >> 8
= 00000000 00000000 00000000 00000011
= 3
```

#### Étape 3 : Vérification
```
3.14 → partie entière = 3 ✅
```

## 🎯 Chapitre 7 : Exemples Pratiques Complets

### 7.1 Exemple 1 : 5.0

#### Conversion int → Fixed
```
5 × 256 = 1280
```

**Décomposition de 1280 :**
```
1280 ÷ 2 = 640 reste 0
640  ÷ 2 = 320 reste 0
320  ÷ 2 = 160 reste 0
160  ÷ 2 = 80  reste 0
80   ÷ 2 = 40  reste 0
40   ÷ 2 = 20  reste 0
20   ÷ 2 = 10  reste 0
10   ÷ 2 = 5   reste 0
5    ÷ 2 = 2   reste 1
2    ÷ 2 = 1   reste 0
1    ÷ 2 = 0   reste 1
```

**Lecture de bas en haut :** 10100000000

**En 32 bits :** 00000000 00000000 00000101 00000000

#### Vérification
```
10100000000 = 1×2¹⁰ + 0×2⁹ + 1×2⁸ + 0×2⁷ + 0×2⁶ + 0×2⁵ + 0×2⁴ + 0×2³ + 0×2² + 0×2¹ + 0×2⁰
= 1024 + 0 + 256 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0
= 1280 ✅
```

### 7.2 Exemple 2 : 0.5

#### Conversion float → Fixed
```
0.5 × 256 = 128
roundf(128) = 128
(int)128 = 128
```

**Décomposition de 128 :**
```
128 ÷ 2 = 64 reste 0
64  ÷ 2 = 32 reste 0
32  ÷ 2 = 16 reste 0
16  ÷ 2 = 8  reste 0
8   ÷ 2 = 4  reste 0
4   ÷ 2 = 2  reste 0
2   ÷ 2 = 1  reste 0
1   ÷ 2 = 0  reste 1
```

**Lecture de bas en haut :** 10000000

**En 32 bits :** 00000000 00000000 00000000 10000000

#### Vérification
```
10000000 = 1×2⁷ + 0×2⁶ + 0×2⁵ + 0×2⁴ + 0×2³ + 0×2² + 0×2¹ + 0×2⁰
= 128 + 0 + 0 + 0 + 0 + 0 + 0 + 0
= 128 ✅
```

### 7.3 Exemple 3 : 2.75

#### Conversion float → Fixed
```
2.75 × 256 = 704
roundf(704) = 704
(int)704 = 704
```

**Décomposition de 704 :**
```
704 ÷ 2 = 352 reste 0
352 ÷ 2 = 176 reste 0
176 ÷ 2 = 88  reste 0
88  ÷ 2 = 44  reste 0
44  ÷ 2 = 22  reste 0
22  ÷ 2 = 11  reste 0
11  ÷ 2 = 5   reste 1
5   ÷ 2 = 2   reste 1
2   ÷ 2 = 1   reste 0
1   ÷ 2 = 0   reste 1
```

**Lecture de bas en haut :** 1011000000

**En 32 bits :** 00000000 00000000 00000010 11000000

#### Vérification
```
1011000000 = 1×2⁹ + 0×2⁸ + 1×2⁷ + 1×2⁶ + 0×2⁵ + 0×2⁴ + 0×2³ + 0×2² + 0×2¹ + 0×2⁰
= 512 + 0 + 128 + 64 + 0 + 0 + 0 + 0 + 0 + 0
= 704 ✅
```

## 🚀 Chapitre 8 : Avantages et Inconvénients

### 8.1 Avantages

1. **Performance** : Opérations entières plus rapides que les float
2. **Précision** : Pas d'erreurs d'arrondi comme avec les float
3. **Prévisibilité** : Comportement déterministe
4. **Contrôle** : Gestion manuelle de la précision

### 8.2 Inconvénients

1. **Gamme limitée** : Avec 8 bits fractionnaires, précision de 1/256 ≈ 0.0039
2. **Débordement** : Risque avec de grandes valeurs
3. **Complexité** : Gestion manuelle des opérations

## 🎓 Chapitre 9 : Résumé Complet

### 9.1 Le processus complet

1. **Int → Fixed :** `rawBits = int × 256`
2. **Float → Fixed :** `rawBits = (int)roundf(float × 256)`
3. **Fixed → Float :** `float = (float)rawBits ÷ 256`
4. **Fixed → Int :** `int = rawBits >> 8`

### 9.2 Les opérations clés

- **Multiplication par 256** = décalage de 8 bits vers la gauche
- **Division par 256** = décalage de 8 bits vers la droite
- **roundf()** = arrondi pour éviter les pertes de précision

### 9.3 La structure mémoire

```
┌─────────────────────────────────────────────────────────────┐
│                   32 bits (int)                            │
├─────────────────┬─────────────────────────────────────────┤
│   Partie entière (24 bits)  │  Partie fractionnaire (8 bits) │
└─────────────────┴─────────────────────────────────────────┘
```

## 🎯 Conclusion

Tu as maintenant une compréhension complète des nombres à virgule fixe ! Tu sais :
- Comment convertir dans tous les sens
- Pourquoi on utilise roundf()
- Comment fonctionne le décalage de bits
- La structure mémoire
- Les avantages et inconvénients

C'est un concept puissant qui te servira dans beaucoup de domaines : jeux vidéo, systèmes embarqués, calculs financiers, etc.

**Continue à pratiquer avec les exercices pour bien maîtriser le concept !** 🚀 