# 📚 COURS : Les nombres à virgule fixe

## 1. Le problème des nombres décimaux en informatique

### Problème avec les flottants :
```cpp
float a = 0.1;
float b = 0.2;
float c = a + b;
// c vaut environ 0.30000000000000004 (pas exactement 0.3 !)
```

### Problème avec les entiers :
```cpp
int prix = 12;  // Comment représenter 12.50 euros ?
```

## 2. La solution : la virgule fixe

### Principe :
- On choisit une **précision fixe** (ex: 2 décimales)
- On multiplie tout par un facteur fixe
- On stocke tout en entiers

### Exemple avec 2 décimales :
```cpp
// Au lieu de stocker 12.50, on stocke 1250
// Au lieu de stocker 3.25, on stocke 325
// Au lieu de stocker 0.99, on stocke 99
```

## 3. Les bits fractionnaires

### Dans ton exercice : 8 bits fractionnaires

- **8 bits** = 2⁸ = 256 valeurs possibles
- **Facteur de multiplication** = 256
- **Précision** = 1/256 ≈ 0.0039

### Exemples de conversion :
```cpp
// Nombre réel → Valeur stockée
1.0    → 1.0 × 256 = 256
0.5    → 0.5 × 256 = 128
0.25   → 0.25 × 256 = 64
2.5    → 2.5 × 256 = 640
```

## 4. Structure de la classe Fixed

```cpp
class Fixed {
private:
    int rawBits;                    // Valeur stockée
    static const int fractionalBits = 8;  // Nombre de bits fractionnaires

public:
    // Constructeurs et destructeur
    Fixed();                        // Initialise à 0
    Fixed(const Fixed& other);      // Constructeur de copie
    ~Fixed();                       // Destructeur
    
    // Opérateurs
    Fixed& operator=(const Fixed& other);  // Opérateur d'affectation
    
    // Méthodes
    int getRawBits() const;         // Retourne la valeur brute
    void setRawBits(int const raw); // Change la valeur brute
};
```

---

# 🎯 EXERCICES D'ENTRAÎNEMENT

## Exercice 1 : QCM - Compréhension

**Question 1 :** Avec 8 bits fractionnaires, combien de valeurs décimales différentes peux-tu représenter entre 0 et 1 ?
- A) 100
- B) 256 V
- C) 255
- D) 8

**Question 2 :** Si tu veux représenter le nombre 2.5 avec 8 bits fractionnaires, quelle valeur entière vas-tu stocker ?
- A) 2.5
- B) 250
- C) 640 V
- D) 25

**Question 3 :** Pourquoi utilise-t-on `static const int` pour `fractionalBits` ?
- A) Pour économiser la mémoire
- B) Pour que la valeur soit partagée entre tous les objets
- C) Pour que la valeur ne puisse pas être modifiée V
- D) B et C

## Exercice 2 : Code à trous

Complète les conversions suivantes :

```cpp
// Avec 8 bits fractionnaires (facteur = 256)
// Nombre réel → Valeur stockée

1.0    → __256___ (1.0 × 256)
0.5    → __128___ (0.5 × 256)
0.25   → __64___ (0.25 × 256)
0.125  → ___32__ (0.125 × 256)
3.75   → _960____ (3.75 × 256)
```

## Exercice 3 : Vrai ou Faux

1. **Les nombres à virgule fixe sont plus précis que les flottants pour les calculs financiers.** V
2. **Avec 8 bits fractionnaires, on peut représenter exactement 0.1.** F
3. **La classe Fixed stocke toujours des valeurs entières.** V
4. **Le constructeur par défaut de Fixed doit initialiser rawBits à 0.** F

---

# 📝 TES RÉPONSES

Écris tes réponses ici :

**QCM :**
- Question 1 : ___B__
- Question 2 : ____C_
- Question 3 : ____C

**Code à trous :**
- 1.0 → __256___
- 0.5 → ____128_
- 0.25 → ___64__
- 0.125 → ____32_
- 3.75 → ___960__

**Vrai ou Faux :**
- 1. _v____
- 2. ___f__
- 3. ___v__
- 4. ____v_

---

**Quand tu as fini, envoie-moi tes réponses pour que je te corrige !** 🚀 