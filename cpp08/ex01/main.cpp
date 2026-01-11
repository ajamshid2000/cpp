/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:34:46 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/25 18:35:27 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <vector>
#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::cout << "\n===== Basic Test =====\n";
    try
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== Duplicate Values (Expect Shortest = 0) =====\n";
    try
    {
        Span sp(4);
        sp.addNumber(5);
        sp.addNumber(1);
        sp.addNumber(5);
        sp.addNumber(10);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== Negative Numbers =====\n";
    try
    {
        Span sp(3);
        sp.addNumber(-10);
        sp.addNumber(0);
        sp.addNumber(10);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== Too Few Elements =====\n";
    try
    {
        Span sp(2);
        sp.addNumber(42);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // should throw
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Overflow Test =====\n";
    try
    {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // should throw
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Large Numbers =====\n";
    try
    {
        Span sp(3);
        sp.addNumber(1000000000);
        sp.addNumber(-1000000000);
        sp.addNumber(0);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== Bulk Random Test =====\n";
    try
    {
        Span sp(20000);
        std::srand(static_cast<unsigned>(std::time(0)));
        for (int i = 0; i < 10000; ++i)
            sp.addNumber(std::rand() % 100000);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << "===== Original Span =====" << std::endl;
        Span original(5);
        original.addNumber(10);
        original.addNumber(20);
        original.addNumber(30);
        std::cout << "Shortest Span: " << original.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << original.longestSpan() << std::endl;
        std::cout << "\n===== Copy Constructor Test =====" << std::endl;
        Span copied(original); // copy constructor
        std::cout << "Shortest Span: " << copied.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << copied.longestSpan() << std::endl;
        std::cout << "\n===== Assignment Operator Test =====" << std::endl;
        Span assigned(3);
        assigned.addNumber(100);
        assigned.addNumber(200);
        assigned = original; // assignment operator
        std::cout << "Shortest Span: " << assigned.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << assigned.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {

        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(4);
        Span sp(5);
        sp.addNumbers(v.begin(), v.end());
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
