# Analyse du Sujet 02 - Surcharge d'opérateurs

## Objectif principal
Cet exercice te demande d'implémenter la surcharge d'opérateurs pour ta classe `Fixed`. C'est un concept fondamental en C++ qui permet de définir comment tes objets se comportent avec les opérateurs mathématiques et de comparaison.

## Concepts à maîtriser

### 1. Surcharge d'opérateurs (Operator Overloading)
- **Qu'est-ce que c'est ?** C'est la possibilité de redéfinir le comportement des opérateurs (+, -, *, /, ==, etc.) pour tes propres classes
- **Pourquoi ?** Pour que tes objets `Fixed` puissent être utilisés naturellement avec les opérateurs mathématiques
- **Comment ?** En définissant des fonctions membres spéciales dans ta classe

### 2. Les différents types d'opérateurs à implémenter

#### Opérateurs de comparaison (6 opérateurs)
- `>`, `<`, `>=`, `<=`, `==`, `!=`
- **Rôle :** Comparer deux objets `Fixed`
- **Retour :** Un booléen (true/false)
- **Réflexion :** Comment compares-tu deux nombres à virgule fixe ? Quelle est la logique derrière chaque comparaison ?

#### Opérateurs arithmétiques (4 opérateurs)
- `+`, `-`, `*`, `/`
- **Rôle :** Effectuer des calculs entre objets `Fixed`
- **Retour :** Un nouvel objet `Fixed` (pas de modification de l'objet original)
- **Réflexion :** Comment effectues-tu ces opérations sur des nombres à virgule fixe ? Faut-il convertir en float puis revenir en Fixed ?

#### Opérateurs d'incrémentation/décrémentation (4 opérateurs)
- `++a` (pré-incrémentation), `a++` (post-incrémentation)
- `--a` (pré-décrémentation), `a--` (post-décrémentation)
- **Rôle :** Augmenter/diminuer la valeur d'un objet `Fixed`
- **Différence pré/post :** 
  - Pré : incrémente puis retourne la nouvelle valeur
  - Post : retourne l'ancienne valeur puis incrémente
- **Réflexion :** Quelle est la valeur de ε (epsilon) ? Comment l'utiliser pour l'incrémentation ?

### 3. Fonctions statiques min/max

#### Concept des fonctions statiques
- **Qu'est-ce ?** Des fonctions qui appartiennent à la classe mais pas à une instance spécifique
- **Comment les appeler ?** `Fixed::max(a, b)` au lieu de `a.max(b)`
- **Pourquoi statiques ?** Parce qu'elles ne modifient pas l'état de l'objet, elles sont utilitaires

#### Surcharge de fonctions
- Tu dois créer **4 fonctions** : `min` et `max` avec deux versions chacune
- **Version 1 :** Prend des références non-constantes
- **Version 2 :** Prend des références constantes
- **Réflexion :** Pourquoi avoir les deux versions ? Quand utiliser l'une ou l'autre ?

## Points techniques importants

### 1. Gestion de la précision
- L'epsilon (ε) est défini comme la plus petite valeur telle que 1 + ε > 1
- **Réflexion :** Comment calcules-tu cette valeur avec tes bits fractionnaires ?

### 2. Const-correctness
- Les fonctions qui ne modifient pas l'objet doivent être marquées `const`
- **Réflexion :** Quelles fonctions doivent être const ? Pourquoi ?

### 3. Retour par valeur vs référence
- **Réflexion :** Quand retourner par valeur ? Quand par référence ? Quand par référence constante ?

## Questions pour t'aider à réfléchir

1. **Pour les opérateurs de comparaison :**
   - Comment compares-tu deux nombres à virgule fixe ?
   - Faut-il les convertir en float pour la comparaison ?

2. **Pour les opérateurs arithmétiques :**
   - Comment effectues-tu une addition entre deux Fixed ?
   - Le résultat doit-il être un nouvel objet ou modifier l'existant ?

3. **Pour l'incrémentation :**
   - Quelle est la valeur de ε dans ton système ?
   - Comment implémentes-tu la différence entre pré et post incrémentation ?

4. **Pour les fonctions statiques :**
   - Pourquoi avoir deux versions (const et non-const) ?
   - Comment choisis-tu quelle version utiliser ?

## Conseils méthodologiques

1. **Commence simple :** Implémente d'abord les opérateurs de comparaison
2. **Teste chaque étape :** Ne passe pas à la suite sans vérifier
3. **Réfléchis à la logique :** Ne code pas au hasard, comprends ce que tu fais
4. **Documente tes choix :** Note pourquoi tu fais chaque choix

## Prochaines étapes

1. Lis attentivement cette analyse
2. Réfléchis aux questions posées
3. Commence par implémenter les opérateurs de comparaison
4. Teste chaque fonctionnalité
5. Pose-moi des questions si tu bloques sur un concept

Veux-tu que je t'explique un concept particulier plus en détail ? 