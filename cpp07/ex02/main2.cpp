/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:16:56 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/20 19:41:18 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    Array<int> a(5);

    for (unsigned int i = 0; i < a.size(); ++i)
        a[i] = i * 2;

    Array<int> b = a;

    b[0] = 42;

    std::cout << "Original array: ";
    for (unsigned int i = 0; i < a.size(); ++i)
        std::cout << a[i] << " ";
    std::cout << "\n";

    std::cout << "Copied array: ";
    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << b[i] << " ";
    std::cout << "\n";

    try {
            for (unsigned int i = 0; i < 10; ++i)
        std::cout << i << ':' << b[i] << " ";
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}