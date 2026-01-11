/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:22:13 by ajamshid          #+#    #+#             */
/*   Updated: 2024/09/25 15:26:39 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "default FragTrap constructor is called" << std::endl;
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}
FragTrap::FragTrap(std::string name_given) : ClapTrap(name_given)
{
    std::cout << "FragTrap constructor with parameter is called" << std::endl;
    name = name_given;
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}
FragTrap::FragTrap(const FragTrap &FragTrap) : ClapTrap(FragTrap)
{
    *this = FragTrap;
}
FragTrap &FragTrap::operator=(const FragTrap &FragTrap)
{

    name = FragTrap.name;
    hit_points = FragTrap.hit_points;
    energy_points = FragTrap.energy_points;
    attack_damage = FragTrap.attack_damage;
    return *this;
}
FragTrap::~FragTrap()
{
    std::cout << "default FragTrap destructor is called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap says,  high five guys" << std::endl;
}
