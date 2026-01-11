/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:53:57 by ajamshid          #+#    #+#             */
/*   Updated: 2024/09/25 16:38:52 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    std::cout << "default DiamondTrap constructor is called" << std::endl;
    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;
}
DiamondTrap::DiamondTrap(std::string name_given) : ClapTrap(name_given), ScavTrap(name_given), FragTrap(name_given)
{
    std::cout << "DiamondTrap constructor with parameter is called" << std::endl;
    DiamondTrap::name = name_given;
    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;
}
DiamondTrap::DiamondTrap(const DiamondTrap &DiamondTrap) : ClapTrap(DiamondTrap), ScavTrap(DiamondTrap), FragTrap(DiamondTrap)
{
    *this = DiamondTrap;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &DiamondTrap)
{

    name = DiamondTrap.name;
    hit_points = DiamondTrap.hit_points;
    energy_points = DiamondTrap.energy_points;
    attack_damage = DiamondTrap.attack_damage;
    return *this;
}
DiamondTrap::~DiamondTrap()
{
    std::cout << "default DiamondTrap destructor is called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
    std::cout << "I am " << DiamondTrap::name << ", my claptrap name is" << ClapTrap::name << std::endl;
}