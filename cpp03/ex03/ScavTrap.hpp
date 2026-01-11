/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:49:17 by ajamshid          #+#    #+#             */
/*   Updated: 2024/09/25 16:59:01 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string name_given);
    ScavTrap(const ScavTrap &ScavTrap);
    ScavTrap &operator=(const ScavTrap &ScavTrap);
    ~ScavTrap();

    void attack(const std::string &target);
    void guardGate();
};

#endif