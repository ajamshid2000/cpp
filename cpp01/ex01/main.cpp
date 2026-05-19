/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:02:10 by ajamshid          #+#    #+#             */
/*   Updated: 2024/11/08 17:42:24 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int i;
    i = 0;

    Zombie new_one;
    Zombie *horde;
    horde = new_one.zombieHorde(10, "something");
    while (i < 10)
    {
        (horde + i)->announce();
        i++;
    }
    delete[] horde;
    return 0;
}
