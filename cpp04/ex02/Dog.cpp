/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:34:33 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/09 15:36:37 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    std::cout << "default Dog constructor is called" << std::endl;
    type = "Dog";
    brain = new Brain;
}
Dog::~Dog()
{
    std::cout << "default Dog destructor is called" << std::endl;
    delete brain;
}
Dog &Dog::operator=(const Dog &dog)
{
    std::cout << "default Dog copy assignement operator is called" << std::endl;
    this->type = dog.type;
    delete brain;
    this->brain = new Brain(*dog.brain);
    return *this;
}
Dog::Dog(const Dog &dog): brain(new Brain(*dog.brain))
{
    std::cout << "default Dog copy constructor is called" << std::endl;
    type = dog.type;
}

void Dog::makeSound() const
{
    std::cout << "woooff woooffff!" << std::endl;
}