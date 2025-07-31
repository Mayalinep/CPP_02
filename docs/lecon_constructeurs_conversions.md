# Leçon : Constructeurs et conversions en virgule fixe

## Concepts clés appris dans cet exercice

### 1. Constructeurs avec paramètres
```cpp
Fixed(const int raw);    // Constructeur avec int
Fixed(const float raw);  // Constructeur avec float
```

**Principe** : Un constructeur peut prendre des paramètres pour initialiser l'objet avec des valeurs spécifiques.

### 2. Conversion en virgule fixe

#### Conversion int → virgule fixe
- **Formule** : `rawBits = int_value * 2^fractional_bits`
- **Exemple** : 10 → 10 * 256 = 2560

#### Conversion float → virgule fixe
- **Formule** : `rawBits = (int)(float_value * 2^fractional_bits + 0.5)`
- **Exemple** : 42.42f → (int)(42.42 * 256 + 0.5) = 10860

### 3. Conversion virgule fixe → autres types

#### Conversion vers float
- **Formule** : `float_value = rawBits / 2^fractional_bits`
- **Exemple** : 2560 → 2560 / 256 = 10.0f

#### Conversion vers int
- **Formule** : `int_value = rawBits / 2^fractional_bits`
- **Exemple** : 2560 → 2560 / 256 = 10

### 4. Surcharge d'opérateur
```cpp
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
```

**Principe** : Permettre l'utilisation de `std::cout << fixed` en redéfinissant l'opérateur `<<`.

## Points importants à retenir

1. **Précision** : La virgule fixe a une précision limitée (8 bits fractionnaires = 256 niveaux)
2. **Arrondi** : Important lors de la conversion float → virgule fixe
3. **Const** : Les fonctions de conversion sont marquées `const` car elles ne modifient pas l'objet
4. **Surcharge** : L'opérateur `<<` doit être déclaré en dehors de la classe

## Applications pratiques

- **Jeux vidéo** : Calculs de position avec précision fixe
- **Systèmes embarqués** : Calculs sans unité de virgule flottante
- **Optimisation** : Calculs plus rapides que les float sur certains processeurs 