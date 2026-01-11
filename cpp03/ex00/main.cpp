/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:22:29 by ajamshid          #+#    #+#             */
/*   Updated: 2024/12/13 15:50:39 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap soldier("soldier");
    soldier.attack("enemy");
    soldier.takeDamage(5);
    soldier.beRepaired(5);
    soldier.takeDamage(5);
    soldier.attack("enemy");
    soldier.attack("enemy");
    soldier.attack("enemy");
    soldier.attack("enemy");
    soldier.attack("enemy");
    soldier.attack("enemy");
    soldier.attack("enemy");
    soldier.attack("enemy");
    soldier.attack("enemy");
    soldier.attack("enemy");
    soldier.attack("enemy");
    soldier.attack("enemy");
    soldier.attack("enemy");
    return 0;
}