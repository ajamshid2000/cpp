/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:37:33 by ajamshid          #+#    #+#             */
/*   Updated: 2024/11/08 16:48:18 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie first;
    first.randomChump("random");
    Zombie *second = first.newZombie("second");
    second->announce();
    delete (second);
    return (0);
}
