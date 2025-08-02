/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:46:01 by mpelage           #+#    #+#             */
/*   Updated: 2025/08/02 15:46:27 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void testPoint(Point const &a, Point const &b, Point const &c, Point const &point, std::string description) {
    std::cout << "Test: " << description << std::endl;
    if (bsp(a, b, c, point))
        std::cout << "✅ Le point est DANS le triangle" << std::endl;
    else
        std::cout << "❌ Le point est HORS du triangle" << std::endl;
    std::cout << "---" << std::endl;
}

int main(void){
    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 3);
    
    std::cout << "Triangle: A(0,0), B(4,0), C(2,3)" << std::endl;
    std::cout << "=====================================" << std::endl;
    
    // Test 1 : Point à l'intérieur
    Point point1(2, 1);
    testPoint(a, b, c, point1, "Point à l'intérieur (2,1)");
    
    // Test 2 : Point à l'extérieur
    Point point2(5, 1);
    testPoint(a, b, c, point2, "Point à l'extérieur (5,1)");
    
    // Test 3 : Point sur un sommet
    Point point3(0, 0);
    testPoint(a, b, c, point3, "Point sur sommet A(0,0)");
    
    // Test 4 : Point sur une arête
    Point point4(2, 0);
    testPoint(a, b, c, point4, "Point sur arête AB (2,0)");
    
    // Test 5 : Point sur une autre arête
    Point point5(1, 1.5);
    testPoint(a, b, c, point5, "Point sur arête AC (1,1.5)");
    
    // Test 6 : Point à l'extérieur (autre côté)
    Point point6(1, -1);
    testPoint(a, b, c, point6, "Point à l'extérieur (1,-1)");
    
    return 0;
}