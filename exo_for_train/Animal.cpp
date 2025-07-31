#include "Animal.hpp"
// À toi d'écrire les définitions ! 


Animal::Animal() : name("INconnu"){}


Animal::Animal(const std::string& name) : name(name){}

Animal::Animal(const Animal& rhs){
	
}

Animal& Animal::operator = (const Animal& rhs){
	if (this != &rhs)
		name = rhs.name;
	return *this;
}

std::string Animal :: afficher() const{
	return name;
}
		Animal :: ~Animal();