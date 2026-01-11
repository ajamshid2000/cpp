/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:57:21 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/09 15:31:50 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "default Brain constructor is called" << std::endl;
}
Brain::~Brain()
{
    std::cout << "default Brain destructor is called" << std::endl;
}
Brain &Brain::operator=(const Brain &brain)
{
    int i;

    i = 0;
    std::cout << "default Brain copy assignement operator is called" << std::endl;
    while (i < 100)
        this->ideas[i] = brain.ideas[i], i++;
    return *this;
}
Brain::Brain(const Brain &brain)
{
    int i;

    i = 0;

    std::cout << "default Brain copy constructor is called" << std::endl;
    if (this != &brain)
        while (i < 100)
            this->ideas[i] = brain.ideas[i], i++;
    *this = brain;
}
