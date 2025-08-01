# Leçon : Algorithme BSP - Point dans un triangle

## 🎯 Objectif
Comprendre l'algorithme pour déterminer si un point est à l'intérieur d'un triangle.

## 📐 Principe de base

### Méthode 1 : Algorithme des déterminants (recommandé)

L'idée est de calculer l'orientation du point par rapport à chaque côté du triangle.

#### Étape 1 : Comprendre l'orientation
- Un point peut être à **gauche**, à **droite** ou **sur** une ligne
- On utilise le **déterminant** pour calculer l'orientation

#### Étape 2 : Formule du déterminant
Pour trois points A(x1,y1), B(x2,y2), P(x,y) :
```
déterminant = (x2-x1)*(y-y1) - (y2-y1)*(x-x1)
```

#### Étape 3 : Interprétation
- Si déterminant > 0 : P est à gauche de AB
- Si déterminant < 0 : P est à droite de AB  
- Si déterminant = 0 : P est sur AB

#### Étape 4 : Algorithme complet
1. Calcule l'orientation du point par rapport au côté AB
2. Calcule l'orientation du point par rapport au côté BC
3. Calcule l'orientation du point par rapport au côté CA
4. Si les trois orientations sont identiques (toutes positives ou toutes négatives) → point à l'intérieur
5. Si une orientation est nulle → point sur une arête → retourne false

## 🧮 Exemple concret

Triangle : A(0,0), B(4,0), C(2,3)
Point à tester : P(2,1)

### Calcul pour le côté AB (A→B) :
- A(0,0), B(4,0), P(2,1)
- déterminant = (4-0)*(1-0) - (0-0)*(2-0) = 4*1 - 0*2 = 4 > 0

### Calcul pour le côté BC (B→C) :
- B(4,0), C(2,3), P(2,1)
- déterminant = (2-4)*(1-0) - (3-0)*(2-4) = (-2)*1 - 3*(-2) = -2 + 6 = 4 > 0

### Calcul pour le côté CA (C→A) :
- C(2,3), A(0,0), P(2,1)
- déterminant = (0-2)*(1-3) - (0-3)*(2-2) = (-2)*(-2) - (-3)*0 = 4 > 0

**Résultat** : Tous les déterminants sont > 0, donc P est à l'intérieur du triangle.

## 💡 Points importants

### Cas limites à gérer :
1. **Point sur un sommet** : au moins un déterminant = 0
2. **Point sur une arête** : au moins un déterminant = 0
3. **Point à l'extérieur** : les déterminants ont des signes différents

### Optimisation :
- Si un déterminant = 0, retourne false immédiatement
- Si les signes sont différents, retourne false immédiatement

## 🧪 Test pratique

Teste cet algorithme avec ces points sur le triangle A(0,0), B(4,0), C(2,3) :
- P(2,1) → devrait être à l'intérieur
- P(5,1) → devrait être à l'extérieur  
- P(0,0) → devrait être sur un sommet
- P(2,0) → devrait être sur une arête

## 📝 Prochaines étapes

1. Comprends bien cette leçon
2. Essaie de calculer manuellement quelques exemples
3. Ensuite, on implémentera la classe Point
4. Puis la fonction bsp()

As-tu des questions sur cette explication ? 