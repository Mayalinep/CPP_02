# Exercices pratiques - BSP (Point dans un triangle)

## 🎯 Exercices de préparation

### Exercice 1 : Comprendre la géométrie
**Objectif** : Visualiser le problème

1. Dessine un triangle sur papier avec les points A(0,0), B(4,0), C(2,3)
2. Place plusieurs points et détermine visuellement s'ils sont à l'intérieur
3. Points à tester : (2,1), (1,1), (3,1), (2,2), (0,0), (4,0)

### Exercice 2 : Algorithme de base
**Objectif** : Comprendre l'algorithme

1. Recherche l'algorithme "test de point dans un triangle"
2. Comprends le principe des produits vectoriels
3. Explique pourquoi cet algorithme fonctionne

### Exercice 3 : Implémentation étape par étape
**Objectif** : Créer la classe Point

1. Crée la classe Point avec les attributs privés
2. Implémente les constructeurs demandés
3. Teste avec des points simples

### Exercice 4 : Algorithme BSP
**Objectif** : Implémenter la fonction bsp()

1. Écris la signature de la fonction
2. Implémente l'algorithme de test
3. Teste avec différents cas

## 🧪 Tests à effectuer

### Cas de test 1 : Point à l'intérieur
- Triangle : A(0,0), B(4,0), C(2,3)
- Point : (2,1)
- Résultat attendu : true

### Cas de test 2 : Point à l'extérieur
- Triangle : A(0,0), B(4,0), C(2,3)
- Point : (5,1)
- Résultat attendu : false

### Cas de test 3 : Point sur un sommet
- Triangle : A(0,0), B(4,0), C(2,3)
- Point : (0,0)
- Résultat attendu : false

### Cas de test 4 : Point sur une arête
- Triangle : A(0,0), B(4,0), C(2,3)
- Point : (2,0)
- Résultat attendu : false

## 📚 Ressources utiles
- Algorithme du déterminant (produit vectoriel)
- Forme canonique en C++
- Classes et objets

## ✅ Checklist de progression
- [ ] Compris l'objectif de l'exercice
- [ ] Créé la classe Point
- [ ] Implémenté la forme canonique
- [ ] Compris l'algorithme BSP
- [ ] Implémenté la fonction bsp()
- [ ] Testé avec différents cas
- [ ] Vérifié tous les cas limites 