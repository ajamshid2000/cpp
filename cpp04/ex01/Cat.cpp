/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:36:23 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/09 15:40:46 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
    std::cout << "default Cat constructor is called" << std::endl;
    type = "Cat";
    brain = new Brain;
}
Cat::~Cat()
{
    std::cout << "default Cat destructor is called" << std::endl;
    delete brain;
}
Cat &Cat::operator=(const Cat &cat)
{
    std::cout << "default Cat copy assignement operator is called" << std::endl;
    this->type = cat.type;
    delete(brain);
    this->brain = new Brain(*cat.brain);
    return *this;
}
Cat::Cat(const Cat &cat):brain(new Brain(*cat.brain))
{
    std::cout << "default Cat copy constructor is called" << std::endl;
    *this = cat;
}

void Cat::makeSound() const
{
    std::cout << "meeeewwwww!" << std::endl;
}
