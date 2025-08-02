#include "Point.hpp"

int main(void){
    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 3);
    Point point(2, 1); // Point à l'intérieur
    
    if (bsp(a, b, c, point))
        std::cout << "Le point (2,1) est dans le triangle" << std::endl;
    else
        std::cout << "Le point (2,1) n'est pas dans le triangle" << std::endl;
} 