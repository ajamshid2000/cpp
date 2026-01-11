/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:57:57 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/19 15:10:26 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "please provide an argument" << std::endl;
        return 0;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}