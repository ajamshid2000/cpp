/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:22:38 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/09 15:12:06 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
    std::cout << "default Animal constructor is called" << std::endl;
    type = "animal";
}
Animal::~Animal()
{
    std::cout << "default Animal destructor is called" << std::endl;
}
Animal &Animal::operator=(const Animal &animal)
{
    std::cout << "default Animal copy assignement operator is called" << std::endl;
    this->type = animal.type;
    return *this;
}
Animal::Animal(const Animal &animal)
{
    std::cout << "default Animal copy constructor is called" << std::endl;
    *this = animal;
}

std::string Animal::getType() const
{
    return (this->type);
}
void Animal::makeSound() const
{
    return;
}
