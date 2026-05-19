/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:02:41 by ajamshid          #+#    #+#             */
/*   Updated: 2024/11/08 17:09:27 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Zombie::Zombie()
// {
//     std::cout << "Default constructor called" << std::endl;
// }

Zombie::~Zombie()
{
    std::cout << "Default destructor called on \"" << this->name << "\"" << std::endl;
}
