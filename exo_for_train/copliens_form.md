# La forme canonique de Coplien en C++

La forme canonique de Coplien est un ensemble de quatre fonctions membres essentielles que toute classe C++ doit posséder pour gérer correctement la mémoire et les ressources. Ces fonctions sont :

## 1. Constructeur par défaut
Crée un objet sans paramètre. Il initialise les membres de la classe à des valeurs par défaut.

## 2. Constructeur de recopie
Permet de créer un nouvel objet comme copie d’un autre objet du même type. Syntaxe :
```cpp
MaClasse(const MaClasse& other);
```

## 3. Opérateur d’affectation
Permet de copier le contenu d’un objet dans un autre déjà existant. Syntaxe :
```cpp
MaClasse& operator=(const MaClasse& other);
```

## 4. Destructeur
Détruit l’objet et libère les ressources associées. Syntaxe :
```cpp
~MaClasse();
```

---

## Pourquoi ces fonctions sont-elles importantes ?
Elles permettent de :
- Gérer correctement la mémoire (éviter les fuites)
- Copier et affecter des objets en toute sécurité
- Respecter la règle des trois (ou cinq avec C++11)

---

## Exemple minimal de classe respectant la forme canonique
```cpp
// Fichier MaClasse.hpp
class MaClasse {
public:
    MaClasse(); // Constructeur par défaut
    MaClasse(const MaClasse& other); // Constructeur de recopie
    MaClasse& operator=(const MaClasse& other); // Opérateur d’affectation
    ~MaClasse(); // Destructeur
private:
    // membres privés
};
```

```cpp
// Fichier MaClasse.cpp
#include "MaClasse.hpp"

MaClasse::MaClasse() {}
MaClasse::MaClasse(const MaClasse& other) {}
MaClasse& MaClasse::operator=(const MaClasse& other) { return *this; }
MaClasse::~MaClasse() {}
```

---

## Conseils
- Toujours séparer la déclaration (.hpp) et l’implémentation (.cpp)
- Si la classe gère des ressources (pointeurs, fichiers, etc.), il faut bien gérer la copie et la destruction
- Utilise `const` et les références pour optimiser les performances

---

N’hésite pas à t’entraîner dans le dossier d’exercices pour bien maîtriser ces concepts ! 