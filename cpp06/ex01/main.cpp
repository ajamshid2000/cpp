/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:57:57 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/19 18:30:18 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data original;
    original.data = 42;

    std::cout << "Original address:   " << &original << std::endl;
    std::cout << "Original value:     " << original.data << std::endl;

    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "Serialized (uintptr_t): " << raw << std::endl;

    Data *deserialized = Serializer::deserialize(raw);

    std::cout << "Deserialized address: " << deserialized << std::endl;
    std::cout << "Deserialized value:   " << deserialized->data << std::endl;

    if (deserialized == &original)
        std::cout << "Success: Same memory address!" << std::endl;
    else
        std::cout << "Error: Different memory address!" << std::endl;

    return 0;
}