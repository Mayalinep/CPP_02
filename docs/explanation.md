## Conversion d'un Entier vers Fixed

### I.a/ Le processus étape par étape 

**Étape 1 :** Prendre l'entier
**Étape 2 :** Multiplier par 256 (2⁸)
**Étape 3 :** Stocker le résultat dans rawBits

### I.b/ Exemple détaillé avec 42

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

**Vérification :**
```
10101000000000 = 1×2¹³ + 0×2¹² + 1×2¹¹ + 0×2¹⁰ + 1×2⁹ + 0×2⁸ + 0×2⁷ + 0×2⁶ + 0×2⁵ + 0×2⁴ + 0×2³ + 0×2² + 0×2¹ + 0×2⁰
= 8192 + 0 + 2048 + 0 + 512 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0
= 10752 ✅
```


