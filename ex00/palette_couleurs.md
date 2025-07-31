# Palette de Couleurs Harmonieuse pour le Code

## 🎨 Palette Recommandée

### Couleurs Principales (pour les inputs)
```bash
# Bleu océan (pour les constructeurs)
BLUE = \033[38;5;33m

# Vert émeraude (pour les getters)
GREEN = \033[38;5;46m

# Orange doux (pour les setters)
ORANGE = \033[38;5;208m

# Violet royal (pour les opérateurs)
PURPLE = \033[38;5;99m

# Rouge corail (pour les destructeurs)
RED = \033[38;5;203m

# Jaune miel (pour les messages d'info)
YELLOW = \033[38;5;220m

# Cyan océan (pour les valeurs)
CYAN = \033[38;5;51m

# Gris argent (pour les messages neutres)
GRAY = \033[38;5;240m
```

### Couleurs de Reset
```bash
RESET = \033[0m
BOLD = \033[1m
```

## 🎯 Application dans votre code

### Version avec couleurs pour Fixed.cpp
```cpp
Fixed::Fixed() : rawBits(0) {
    std::cout << BLUE << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& rhs) {
    std::cout << PURPLE << "Copy constructor called" << RESET << std::endl;
    *this = rhs;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
    std::cout << ORANGE << "Copy assignment operator called" << RESET << std::endl;
    if (this != &rhs) {
        rawBits = rhs.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << GREEN << "getRawBits member function called" << RESET << std::endl;
    return rawBits;
}

void Fixed::setRawBits(int const raw) {
    std::cout << YELLOW << "setRawBits called with value: " << raw << RESET << std::endl;
    rawBits = raw;
}

Fixed::~Fixed() {
    std::cout << RED << "Destructor called" << RESET << std::endl;
}
```

### Version avec couleurs pour main.cpp
```cpp
int main(void) {
    std::cout << CYAN << "=== Début du programme ===" << RESET << std::endl;
    
    std::cout << BLUE << "Création de l'objet 'a'" << RESET << std::endl;
    Fixed a;
    
    std::cout << PURPLE << "Création de l'objet 'b' (copie de 'a')" << RESET << std::endl;
    Fixed b(a);
    
    std::cout << BLUE << "Création de l'objet 'c'" << RESET << std::endl;
    Fixed c;
    
    std::cout << ORANGE << "Affectation: c = b" << RESET << std::endl;
    c = b;
    
    std::cout << GREEN << "Affichage des valeurs:" << RESET << std::endl;
    std::cout << "a.getRawBits() = " << CYAN << a.getRawBits() << RESET << std::endl;
    std::cout << "b.getRawBits() = " << CYAN << b.getRawBits() << RESET << std::endl;
    std::cout << "c.getRawBits() = " << CYAN << c.getRawBits() << RESET << std::endl;
    
    std::cout << GRAY << "=== Fin du programme ===" << RESET << std::endl;
    return 0;
}
```

## 🎨 Palette Alternative (Plus Subtile)

Si vous préférez des couleurs plus douces :

```bash
# Bleu ciel
BLUE_SOFT = \033[38;5;74m

# Vert menthe
GREEN_SOFT = \033[38;5;78m

# Orange pêche
ORANGE_SOFT = \033[38;5;209m

# Violet lavande
PURPLE_SOFT = \033[38;5;147m

# Rouge rose
RED_SOFT = \033[38;5;211m

# Jaune crème
YELLOW_SOFT = \033[38;5;229m
```

## 🚀 Intégration dans votre Makefile

```makefile
# Couleurs pour les messages de compilation
BLUE = \033[38;5;33m
GREEN = \033[38;5;46m
ORANGE = \033[38;5;208m
RED = \033[38;5;203m
RESET = \033[0m

# Messages colorés
$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(ORANGE)Cleaning $(NAME)...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
```

## 🎯 Avantages de cette palette

1. **Lisibilité** : Chaque type d'opération a sa couleur
2. **Harmonie** : Couleurs qui se complètent bien
3. **Accessibilité** : Contrastes suffisants
4. **Professionnalisme** : Couleurs élégantes et modernes

## 💡 Conseils d'utilisation

- **Constructeurs** : Bleu (création)
- **Getters** : Vert (lecture)
- **Setters** : Jaune (écriture)
- **Opérateurs** : Orange/Violet (opérations)
- **Destructeurs** : Rouge (destruction)
- **Valeurs** : Cyan (données)
- **Messages** : Gris (neutre)

Voulez-vous que j'applique cette palette à votre code actuel ? 