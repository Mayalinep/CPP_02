# Questions de compréhension - Exercice 03 (BSP)

## 🎯 Objectif de l'exercice
L'objectif est de créer une fonction qui détermine si un point est à l'intérieur d'un triangle.

## 📋 Questions pour vérifier ta compréhension

### 1. Classe Point
- **Question 1** : Quels sont les attributs privés nécessaires pour la classe Point ?
- **Question 2** : Pourquoi les attributs x et y doivent-ils être constants ?
- **Question 3** : Quels constructeurs sont demandés pour la classe Point ?

### 2. Forme canonique
- **Question 4** : Qu'est-ce que la forme canonique d'une classe en C++ ?
- **Question 5** : Quels sont les éléments obligatoires de la forme canonique ?

### 3. Fonction BSP
- **Question 6** : Que signifie BSP ? (indice : Binary Space Partitioning)
- **Question 7** : Quels sont les paramètres de la fonction bsp() ?
- **Question 8** : Dans quels cas la fonction doit-elle retourner False ?

### 4. Algorithme
- **Question 9** : Connais-tu un algorithme pour déterminer si un point est dans un triangle ?
- **Question 10** : Comment peux-tu utiliser les coordonnées des points pour résoudre ce problème ?

## 🧠 Concepts à maîtriser
- Classes et objets en C++
- Forme canonique
- Géométrie 2D
- Algorithme de test de point dans un triangle

## 📝 Tes réponses
Écris tes réponses ici :

--- 1. les attribut necessaire sont fixed x et fixed y car ils sont le point a verifier en 2D
    2. les attributs sont const car il ne doivent pas etre modifier mais juste verifier
    3.un constructeur par defaut, un constructeur avec deux float en paramettre, une copie, un surcharge d'affectation, un destructeur
    4.5. la forme canonique est une classe qui a un constructeur par defaut, un constructeur avec des paramettre, une copie, un surcharge d'affectation, un destructeur
    6. BSP est un algorithme de partitionnement de l'espace qui permet de determiner si un point est dans une zone donnee
    7. a, b, c : les sommets du triangles et les coordonnées du point a verifier
    8. si le point est un sommet ou placé sur une arrête, la fonction retournera False. si le point n'est pas a l interieur du triangle, la fonction retournera False.
    9. non du tout
    10. je sais pas