/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:08:35 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/14 19:02:28 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const &type) : type(type) {}

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter &target)
{
    if (this->type == "ice")
        std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    if (this->type == "cure")
        std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}