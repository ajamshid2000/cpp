/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:22:28 by ajamshid          #+#    #+#             */
/*   Updated: 2024/09/25 15:29:44 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string name_given);
    FragTrap(const FragTrap &FragTrap);
    FragTrap &operator=(const FragTrap &FragTrap);
    ~FragTrap();

    void highFivesGuys(void);
};

#endif