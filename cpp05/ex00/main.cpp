/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:10:42 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/16 15:24:03 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// int main()
// {
//     Bureaucrat hello;
//     std::cout << "hello" << hello;
//     return 0;
// }

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Basic Valid Construction ===" << std::endl;
    Bureaucrat b1("Alice", 42);
    std::cout << b1 << std::endl;

    std::cout << "\n=== Default Constructor ===" << std::endl;
    Bureaucrat b2;
    std::cout << b2 << std::endl;

    std::cout << "\n=== Copy Constructor ===" << std::endl;
    Bureaucrat b3(b1);
    std::cout << b3 << std::endl;

    std::cout << "\n=== Assignment Operator ===" << std::endl;
    b2 = b1;
    std::cout << b2 << std::endl;

    std::cout << "\n=== Grade Increment ===" << std::endl;
    try
    {
        Bureaucrat b4("Bob", 2);
        std::cout << b4 << std::endl;
        b4.increment(); // should work
        std::cout << "After increment: " << b4 << std::endl;
        b4.increment(); // should throw
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Grade Decrement ===" << std::endl;
    try
    {
        Bureaucrat b5("Charlie", 149);
        std::cout << b5 << std::endl;
        b5.decrement(); // should work
        std::cout << "After decrement: " << b5 << std::endl;
        b5.decrement(); // should throw
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid Construction (Too High) ===" << std::endl;
    try
    {
        Bureaucrat b6("Dave", 0); // should throw
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid Construction (Too Low) ===" << std::endl;
    try
    {
        Bureaucrat b7("Eve", 151); // should throw
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
