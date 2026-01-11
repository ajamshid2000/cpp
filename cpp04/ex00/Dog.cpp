/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:34:33 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/09 15:12:41 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    std::cout << "default Dog constructor is called" << std::endl;
    type = "Dog";
}
Dog::~Dog()
{
    std::cout << "default Dog destructor is called" << std::endl;
}
Dog &Dog::operator=(const Dog &dog)
{
    std::cout << "default Dog copy assignement operator is called" << std::endl;
    this->type = dog.type;
    return *this;
}
Dog::Dog(const Dog &dog)
{
    std::cout << "default Dog copy constructor is called" << std::endl;
    *this = dog;
}

void Dog::makeSound() const
{
    std::cout << "woooff woooffff!" << std::endl;
}