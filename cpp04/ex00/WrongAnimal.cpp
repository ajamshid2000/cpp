/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:19:26 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/09 15:12:56 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
    std::cout << "default WrongAnimal constructor is called" << std::endl;
    type = "animal";
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "default WrongAnimal destructor is called" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{
    std::cout << "default WrongAnimal copy assignement operator is called" << std::endl;
    this->type = animal.type;
    return *this;
}
WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
    std::cout << "default WrongAnimal copy constructor is called" << std::endl;
    *this = animal;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}
void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound!" << std::endl;
    return;
}