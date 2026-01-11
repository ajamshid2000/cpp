/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:21:13 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/20 18:39:52 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>

void swap(T &a, T &b)
{
    std::swap(a, b);
    return;
}

template <typename T>
T min(T a, T b)
{
    if (a == b)
        return b;
    return std::min(a, b);
}

template <typename T>
T max(T a, T b)
{
    if (a == b)
        return b;
    return std::max(a, b);
}

#endif