/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:16:56 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/20 18:49:12 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printInt(char x)
{
    std::cout << x << " ";
    x++;
    std::cout << x << " ";
}

int main(void)
{

    // int arr[] = {1, 3, 5, 7, 9};
    // iter(arr, 5, printInt);
    char arr2[] = {'a', 'c', 'e', 'g', 'i'};
    iter(arr2, 5, printInt);

    return 0;
}