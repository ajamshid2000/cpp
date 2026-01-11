/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:52:58 by ajamshid          #+#    #+#             */
/*   Updated: 2024/09/25 16:53:07 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
{
    std::cout << "default constructor is called" << std::endl;
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;
}
ClapTrap::ClapTrap(std::string name_given)
{
    std::cout << "constructor with parameter is called" << std::endl;
    name = name_given;
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;
}
ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
    *this = claptrap;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
    name = claptrap.name;
    hit_points = claptrap.hit_points;
    energy_points = claptrap.energy_points;
    attack_damage = claptrap.attack_damage;
    return *this;
}
ClapTrap::~ClapTrap()
{
    std::cout << "default destructor is called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (hit_points <= 0 || energy_points <= 0)
        return;
    std::cout << "ClapTrap " << name << " attacks " << target << " ,causing " << attack_damage << " points of damage" << std::endl;
    energy_points--;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points <= 0 || energy_points <= 0)
        return;
    std::cout << "ClapTrap " << name << " is attacked ,taking " << amount << " points of damage" << std::endl;
    hit_points -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (hit_points <= 0 || energy_points <= 0)
        return;
    std::cout << "ClapTrap " << name << " is being repaired, by taking " << amount << " repaire points" << std::endl;
    hit_points += amount;
    energy_points--;
}