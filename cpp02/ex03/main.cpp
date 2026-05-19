/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:03:25 by ajamshid          #+#    #+#             */
/*   Updated: 2024/12/13 17:54:55 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

// int main(void)
// {
//     Point a(1, 1);
//     Point b(1, 5);
//     Point c(5, 1);
//     if (bsp(a, b, c, Point(1, 3)))
//         std::cout << "\n\n\n"
//                   << "it is inside the triangle" << "\n\n"
//                   << std::endl;
//     else
//         std::cout << "\n\n\n"
//                   << "it is outside the triangle" << "\n\n"
//                   << std::endl;
//     if (bsp(a, b, c, Point(5, 2)))
//         std::cout << "\n\n\n"
//                   << "it is inside the triangle" << "\n\n"
//                   << std::endl;
//     else
//         std::cout << "\n\n\n"
//                   << "it is outside the triangle" << "\n\n"
//                   << std::endl;
//     if (bsp(a, b, c, Point(2, 1.1)))
//         std::cout << "\n\n\n"
//                   << "it is inside the triangle" << "\n\n"
//                   << std::endl;
//     else
//         std::cout << "\n\n\n"
//                   << "it is outside the triangle" << "\n\n"
//                   << std::endl;
//     return 0;
// }


int main() {
    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 3);

    Point inside1(2, 1);
    Point inside2(1, 1);
    Point inside3(2.5, 1);
    Point inside4(1.5, 0.5);
    Point inside5(3, 1);

    Point outside1(5, 5);
    Point outside2(-1, -1);
    Point outside3(4, 4);
    Point outside4(0, 4);
    Point outside5(6, 0);

    Point on_edge1(2, 0);
    Point on_edge2(3, 1.5);
    Point on_edge3(1, 1.5);
    Point corner1(0, 0);
    Point corner2(4, 0);

    std::cout << "Test 1     (inside): " << (bsp(a, b, c, inside1) ? "True" : "False") << std::endl;
    std::cout << "Test 2     (inside): " << (bsp(a, b, c, inside2) ? "True" : "False") << std::endl;
    std::cout << "Test 3     (inside): " << (bsp(a, b, c, inside3) ? "True" : "False") << std::endl;
    std::cout << "Test 4     (inside): " << (bsp(a, b, c, inside4) ? "True" : "False") << std::endl;
    std::cout << "Test 5     (inside): " << (bsp(a, b, c, inside5) ? "True" : "False") << std::endl;

    std::cout << "Test 6    (outside): " << (bsp(a, b, c, outside1) ? "True" : "False") << std::endl;
    std::cout << "Test 7    (outside): " << (bsp(a, b, c, outside2) ? "True" : "False") << std::endl;
    std::cout << "Test 8    (outside): " << (bsp(a, b, c, outside3) ? "True" : "False") << std::endl;
    std::cout << "Test 9    (outside): " << (bsp(a, b, c, outside4) ? "True" : "False") << std::endl;
    std::cout << "Test 10   (outside): " << (bsp(a, b, c, outside5) ? "True" : "False") << std::endl;

    std::cout << "Test 11   (on edge): " << (bsp(a, b, c, on_edge1) ? "True" : "False") << std::endl;
    std::cout << "Test 12   (on edge): " << (bsp(a, b, c, on_edge2) ? "True" : "False") << std::endl;
    std::cout << "Test 13   (on edge): " << (bsp(a, b, c, on_edge3) ? "True" : "False") << std::endl;
    std::cout << "Test 14 (on corner): " << (bsp(a, b, c, corner1) ? "True" : "False") << std::endl;
    std::cout << "Test 15 (on corner): " << (bsp(a, b, c, corner2) ? "True" : "False") << std::endl;

    return 0;
}