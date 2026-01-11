/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:50:55 by ajamshid          #+#    #+#             */
/*   Updated: 2024/09/25 14:34:44 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "default ScavTrap constructor is called" << std::endl;
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
}
ScavTrap::ScavTrap(std::string name_given) : ClapTrap(name_given)
{
    std::cout << "ScavTrap constructor with parameter is called" << std::endl;
    name = name_given;
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
}
ScavTrap::ScavTrap(const ScavTrap &ScavTrap) : ClapTrap(ScavTrap)
{
    *this = ScavTrap;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &ScavTrap)
{

    name = ScavTrap.name;
    hit_points = ScavTrap.hit_points;
    energy_points = ScavTrap.energy_points;
    attack_damage = ScavTrap.attack_damage;
    return *this;
}
ScavTrap::~ScavTrap()
{
    std::cout << "default ScavTrap destructor is called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (hit_points == 0 || energy_points == 0)
        return;
    std::cout << "ScavTrap " << name << " attacks " << target << " ,causing " << attack_damage << " points of damage" << std::endl;
    energy_points--;
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
}
