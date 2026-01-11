/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:21:29 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/25 18:57:41 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>

class Span
{
private:
    int *arr;
    int size;
    int last_element;

public:
    Span();
    Span(unsigned int N);
    ~Span();
    Span(const Span &other);
    Span &operator=(const Span &other);
    unsigned int shortestSpan();
    unsigned int longestSpan();
    void addNumber(int N);
    template <typename iterator>
    void addNumbers(iterator begin, iterator end)
    {
        while (begin != end)
        {
            addNumber(*begin);
            ++begin;
        }
    }
};

#endif