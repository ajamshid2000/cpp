/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:15:09 by ajamshid          #+#    #+#             */
/*   Updated: 2025/01/09 15:12:50 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Animal.hpp"

#ifndef DOG_HPP
#define DOG_HPP

class Dog: public Animal
{
public:
    Dog();
    ~Dog();
    Dog &operator=(const Dog &dog);
    Dog(const Dog &dog);

    void makeSound() const;
};

#endif
