#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
	private:
		std::string name;

	public:
		Animal();
		Animal(const std:string& name);
		Animal(const Animal& rhs);
		Animal& operator = (const Animal& rhs);
		std::string afficher() const;
		~Animal();
};

#endif 