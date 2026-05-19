/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:42:54 by ajamshid          #+#    #+#             */
/*   Updated: 2024/09/20 16:04:39 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie *Zombie::zombieHorde(int N, std::string name)
{
    Zombie *hord = new Zombie[N];
    int i;
    
    i = 0;
    while (i < N)
    {
        hord[i].name = name;
        i++;
    }
    return (&hord[0]);
}
