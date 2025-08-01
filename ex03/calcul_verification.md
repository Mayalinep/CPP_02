# Calculs de vérification - Point P(5,1) dans triangle A(0,0), B(4,0), C(2,3)

## 🧮 Calculs détaillés

### Triangle : A(0,0), B(4,0), C(2,3)
### Point à tester : P(5,1)

## Calcul 1 : Côté AB (A→B)
- A(0,0), B(4,0), P(5,1)
- Formule : (x2-x1)*(y-y1) - (y2-y1)*(x-x1)
- (4-0)*(1-0) - (0-0)*(5-0)
- 4*1 - 0*5
- 4 - 0 = **4** ✅

## Calcul 2 : Côté BC (B→C)
- B(4,0), C(2,3), P(5,1)
- Formule : (x2-x1)*(y-y1) - (y2-y1)*(x-x1)
- (2-4)*(1-0) - (3-0)*(5-4)
- (-2)*1 - 3*1
- -2 - 3 = **-5** ❌

Tu as trouvé 5, mais c'est -5 !

## Calcul 3 : Côté CA (C→A)
- C(2,3), A(0,0), P(5,1)
- Formule : (x2-x1)*(y-y1) - (y2-y1)*(x-x1)
- (0-2)*(1-3) - (0-3)*(5-2)
- (-2)*(-2) - (-3)*3
- 4 - (-9) = 4 + 9 = **13** ✅

## 🎯 Résultats
- AB : 4 (positif)
- BC : -5 (négatif) 
- CA : 13 (positif)

## 💡 Interprétation
Les signes sont **différents** :
- AB : positif
- BC : négatif
- CA : positif

**Conclusion** : Le point P(5,1) est à l'**extérieur** du triangle ✅

## 🔍 Vérification visuelle
Si tu dessines le triangle A(0,0), B(4,0), C(2,3) et places le point P(5,1), tu verras qu'il est effectivement à l'extérieur !

## ❌ Ton erreur
Tu as fait une erreur dans le calcul BC. Vérifie bien les signes !
- (2-4) = -2 (pas 2)
- (3-0) = 3
- (5-4) = 1

Donc : (-2)*1 - 3*1 = -2 - 3 = -5 