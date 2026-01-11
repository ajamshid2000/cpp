/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:21:21 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/27 16:17:51 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <limits.h>
#include <algorithm>

Span::Span() : arr(new int[5]), size(5), last_element(0)
{
}

Span::Span(unsigned int N) : arr(new int[N]), size(N), last_element(0)
{
}

Span::~Span()
{
    delete[] (arr);
}

Span::Span(const Span &other) : arr(new int[other.size]), size(other.size), last_element(other.last_element)
{
    std::copy(other.arr, other.arr + size, arr);
}
Span &Span::operator=(const Span &other)
{
    if (this == &other)
        return *this;
    delete[] (arr);
    arr = new int[other.size];
    std::copy(other.arr, other.arr + other.size, this->arr);
    size = other.size;
    last_element = other.last_element;

    return *this;
}

unsigned int Span::shortestSpan()
{
    if (last_element < 2)
        throw std::runtime_error("no span");
    int *temp = new int[size];
    std::copy(arr, arr + size, temp);

    std::sort(temp, temp + size);
    unsigned int span = UINT_MAX;
    for (int i = 1; i < size; ++i)
    {
        unsigned int diff = temp[i] - temp[i - 1];
        if (diff < span)
        {
            span = diff;
        }
    }
    return span;
}

unsigned int Span::longestSpan()
{
    if (last_element < 2)
        throw std::runtime_error("no span");
    int *a = std::min_element(arr, arr + size);
    int *b = std::max_element(arr, arr + size);
    return (unsigned int)abs(*a - *b);
}

void Span::addNumber(int N)
{
    if (last_element >= size)
    {
        throw std::runtime_error("Span full");
        return;
    }
    arr[last_element] = N;
    ++last_element;
}
