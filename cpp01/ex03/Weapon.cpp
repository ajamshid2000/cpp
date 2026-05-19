/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:22:35 by ajamshid          #+#    #+#             */
/*   Updated: 2024/09/23 14:46:51 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string &Weapon::getType()
{
    return (type);
}

void Weapon::setType(std::string type)
{
    Weapon::type = type;
}

Weapon::Weapon(std::string type_given)
{
    type = type_given;
}
