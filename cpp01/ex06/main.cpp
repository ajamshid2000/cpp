/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:48:42 by ajamshid          #+#    #+#             */
/*   Updated: 2024/11/08 18:31:18 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    int i;
    i = 0;

    if (argc > 2 || argc < 2)
    {
        std::cout << "please pass a level as an argumnet!!" << std::endl;
        return 0;
    }

    std::string level = argv[1];
    char levelsC[5][10] = {"DEBUG", "INFO", "WARNING", "ERROR", {'\0'}};
    char levels[5][10] = {"debug", "info", "warning", "error", {'\0'}};
    while (level.compare(levelsC[i]) && i < 4)
        i++;

    Harl my_obj;
    switch (i)
    {
    case 0:
        std::cout << '[' << levelsC[i] << ']' << std::endl;
        my_obj.complain(levels[i]);
        std::cout << std::endl;
        i++;
    case 1:
        std::cout << '[' << levelsC[i] << ']' << std::endl;
        my_obj.complain(levels[i]);
        std::cout << std::endl;
        i++;
    case 2:
        std::cout << '[' << levelsC[i] << ']' << std::endl;
        my_obj.complain(levels[i]);
        std::cout << std::endl;
        i++;
    case 3:
        std::cout << '[' << levelsC[i] << ']' << std::endl;
        my_obj.complain(levels[i]);
        std::cout << std::endl;
        break;
    case 4:
        std::cout << '[' << " Probably complaining about insignificant problems " << ']' << std::endl;
        std::cout << std::endl;
        break;
    }

    return 0;
}

// my_obj.complain("debug");
// my_obj.complain("info");
// my_obj.complain("warning");
// my_obj.complain("error");
// }